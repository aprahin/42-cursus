/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:25:24 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 16:32:03 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_log_op(void *tok_key)
{
	const int	k = *(int *)&tok_key;

	return (k == LEX_KEY_AND || k == LEX_KEY_OR);
}

//
//add_node(all_groups, tkn_cursor->key, NULL)
//
//3////t_lst *groups = void* of key - int type(of group)
//and value - t_lst	*group
//made in add_group_to_groups(), stored as a variable in prs_and_exec()
//type(of groups) - CMD_TYPE_BI_BIN	CMD_TYPE_PIPE CMD_TYPE_SUBSH	
//
//account for log op that follow group add_node(all_groups, tkns_kv->key, 0)
//
static int	add_group_to_groups(t_lst *groups, t_lst *group,
		t_key_val_lst *tkn_kv, long type)
{
	if (group->size && add_node(groups, (void *)type, group))
	{
		hfree_tlst(group);
		return (shell_err(1, "Error: add_group_to_groups()", 1, 0));
	}
	if (!group->size)
		hfree_tlst(group);
	if (tkn_kv && is_log_op(tkn_kv->key) && add_node(groups, tkn_kv->key, NULL))
		return (shell_err(1, "Error: add_group_to_groups()", 1, 0));
	return (EXIT_SUCCESS);
}

//
//add_node(one_gr, (*tkn_kv)->key, (*tkn_kv)->val)
//
//copy tlst tokens key values to tlst group 
//
//2////t_lst	*group = void* of key - int (LEX_KEY) and value - char *
//made in tkns_to_one_group() (with long type
//of the group), stored in t_lst *groups 
//
//in tkns_to_one_group() we split cmds into groups by:
//1) log op because parts of log expr have to be executed separately
//2) paranteses () as every subshell has to be executed in a separate process
//
//group is tokens that have to be executed
//in a subshell or are a part of logical expression
//group is tokens from t_lst tokens until
//&& || or inside the highest lvl subshell ()
//if && || () | are inside subshell () we write them as part of the group
//only the insides of the subshell () are written without the outer parantheses
//
//checks if number of left and right parantheses are equal and counteract
//increases/decreases lvl of paranteses for (par_lvl += 1, for) -= 1
//
//par_lvl>0 means token is inside of unclosed parantheses sequence
//and has to be executed in a subshell. set its type to CMD_TYPE_SUBSH
//
//| && !par_lvl set its type to to CMD_TYPE_PIPE
//
/*int	pipe_sub(void *key, int type)
{
	const int	k = *(int *)&key;
	if ((type & CMD_TYPE_PIPE) && (k == LEX_KEY_PARN_L))
		return (1);
	return (0);
}*/

static int	tkns_to_one_group(t_lst *group, t_key_val_lst **tkn_kv,
		long *type, int *lvl)
{
	while (*tkn_kv && (*tkn_kv)->key == LEX_KEY_SEP)
		*tkn_kv = (*tkn_kv)->next;
	while (*tkn_kv && (*lvl > 0 || !is_log_op((*tkn_kv)->key)))
	{
		(*lvl) += (*(int *)&(*tkn_kv)->key == LEX_KEY_PARN_L);
		(*lvl) -= (*(int *)&(*tkn_kv)->key == LEX_KEY_PARN_R);
		if (*lvl < 0)
			return (shell_err(1, ERR_PRS_PARN, 0, 2));
		(*type) |= (*lvl > 0) << 5;
		(*type) |= (*(int *)&(*tkn_kv)->key == LEX_KEY_PIPE && !(*lvl)) << 6;
		if (add_node(group, (*tkn_kv)->key, (*tkn_kv)->val))
			return (shell_err(1, "Error: tkns_to_one_group()", 1, 0));
		*tkn_kv = (*tkn_kv)->next;
	}
	return (EXIT_SUCCESS);
}

//
//3////t_lst *groups = void* of key - int type(of group)
//and value - t_lst	*group
//made in add_group_to_groups(), stored as a variable in prs_and_exec()
//type(of groups) - CMD_TYPE_BI_BIN	CMD_TYPE_PIPE CMD_TYPE_SUBSH	
//set default type to CMD_TYPE_BI_BIN, 	CMD_TYPE_PIPE
//CMD_TYPE_SUBSH are set in tkns_to_one_group()
//group of 1 lvl are discarded
//
int	prs_tkns_into_groups(t_lst *groups, t_lst *tokens)
{
	t_key_val_lst	*tkn_cursor;
	t_lst			*group;
	long			type;
	int				lvl;

	tkn_cursor = tokens->head;
	while (tkn_cursor)
	{
		group = new_tlst(NULL, NULL, NULL);
		if (!group)
			return (shell_err(1, "Error: prs_tkns_into_groups()", 1, 0));
		type = CMD_TYPE_BI_BIN;
		lvl = 0;
		if (tkns_to_one_group(group, &tkn_cursor, &type, &lvl))
			return (EXIT_FAILURE);
		if (lvl && hfree_tlst_ret1(group))
			return (shell_err(1, ERR_PRS_PARN, 0, 2));
		if (add_group_to_groups(groups, group, tkn_cursor, type))
			return (EXIT_FAILURE);
		if (tkn_cursor)
			tkn_cursor = tkn_cursor->next;
	}
	return (EXIT_SUCCESS);
}

//
//3////t_lst *groups = void* of key - int type(of group)
//and value - t_lst	*group
//made in add_group_to_groups(), stored as a variable in prs_and_exec()
//
int	check_log_op(t_lst *groups)
{
	t_key_val_lst	*ptr;
	int				expected;

	expected = 0;
	ptr = groups->head;
	while (ptr)
	{
		if (!expected && is_log_op(ptr->key))
			return (shell_err(1, ERR_PRS_LOG, 0, 2));
		else
			expected = 1;
		if (expected == 1 && is_log_op(ptr->key))
			expected = 0;
		ptr = ptr->next;
	}
	if (!expected)
		return (shell_err(1, ERR_PRS_LOG, 0, 2));
	return (EXIT_SUCCESS);
}
