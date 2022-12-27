/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:25:53 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/26 18:44:14 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//
//set tcmd type to token key value
//sets tcmd type, file_in (<, <<), file out (>, >>)
//cmd_to_inp < - 0b101 (~CMD_TO_HEREDOC), cmd_to_out > - 0b110 (~CMD_TO_APPEND)
//checks syntax
//

static int	groups_and_group_to_args3(t_key_val_lst **tkn, t_cmd_info *tcmd)
{
	if (*(int *)&(*tkn)->key == LEX_KEY_REDIR_OUT
		|| *(int *)&(*tkn)->key == LEX_KEY_REDIR_APPEND)
	{
		if (handle_middle_file(tcmd) != 0)
			return (EXIT_SUCCESS);
		if (*(int *)&(*tkn)->key == LEX_KEY_REDIR_APPEND)
			tcmd->type |= CMD_TO_APPEND;
		else
			tcmd->type &= ~CMD_TO_APPEND;
		*tkn = get_next_tkn(*tkn);
		if (!*tkn || *(int *)&(*tkn)->key != LEX_KEY_WORD)
			return (shell_err(1, ERR_PRS_RREDIR, 0, 2));
		tcmd->file_out = (*tkn)->val;
		handle_middle_file(tcmd);
	}
	return (EXIT_SUCCESS);
}

static int	groups_and_group_to_args2(t_key_val_lst **tkn, t_cmd_info *tcmd)
{
	if (*(int *)&(*tkn)->key == LEX_KEY_REDIR_IN
		|| *(int *)&(*tkn)->key == LEX_KEY_HEREDOC)
	{
		if (handle_middle_file_in(tcmd) != 0)
			return (EXIT_SUCCESS);
		if (*(int *)&(*tkn)->key == LEX_KEY_HEREDOC)
			tcmd->type |= CMD_TO_HEREDOC;
		else
			tcmd->type &= ~CMD_TO_HEREDOC;
		*tkn = get_next_tkn(*tkn);
		if (!*tkn || *(int *)&(*tkn)->key != LEX_KEY_WORD)
			return (shell_err(1, ERR_PRS_LREDIR, 0, 2));
		tcmd->file_in = (*tkn)->val;
		return (EXIT_SUCCESS);
	}
	return (groups_and_group_to_args3(tkn, tcmd));
}

//
//break group into args by pipes
//
//for group without pipes
//4A////t_lst	*args = void* of key - int (LX_SEP) and value - char * 
//args is tkns from t_lst group until the end of subshell ()
//made in  groups_and_group_to_args), stored in t_lst	*cmds
//
//for group with pipes
//4B////t_lst	*args = void* of key - int type(of group)
// and value - t_lst	*group 
//args is group from t_lst groups until
//the end of subshell ()  or pipe outside ()
//made in  groups_and_group_to_args), stored in t_lst	*cmds
//
//ignore whitespaces outside subshell
//set cmd type and subshell_level
//check for syntax errors
//add_node(args, (*tkn)->key, (*tkn)->val)
//

int	groups_and_group_to_args(t_key_val_lst **tkn, t_cmd_info *tcmd,
		t_lst *args)
{
	if (!(*tkn))
		return (shell_err(1, "Error: groups_and_group_to_args()", 0, 999));
	if (*(int *)&(*tkn)->key == LEX_KEY_PARN_L
		|| *(int *)&(*tkn)->key == LEX_KEY_PARN_R)
	{
		tcmd->subsh_lvl += (*(int *)&(*tkn)->key == LEX_KEY_PARN_L)
			+ (-1) * (*(int *)&(*tkn)->key == LEX_KEY_PARN_R);
		tcmd->type |= CMD_TO_SUBSH;
		if ((tcmd->subsh_lvl == 1 && *(int *)&(*tkn)->key == LEX_KEY_PARN_L)
			|| (!tcmd->subsh_lvl && *(int *)&(*tkn)->key == LEX_KEY_PARN_R))
			return (EXIT_SUCCESS);
	}
	if (*(int *)&(*tkn)->key == LEX_KEY_SEP && !tcmd->subsh_lvl)
		return (EXIT_SUCCESS);
	if ((tcmd->type & CMD_TO_SUBSH) && !(tcmd->subsh_lvl)
		&& *(int *)&(*tkn)->key == LEX_KEY_WORD)
		return (shell_err(1, ERR_PRS_PARN, 0, 2));
	if ((*(int *)&(*tkn)->key == LEX_KEY_WORD || tcmd->subsh_lvl > 0)
		&& add_node(args, (*tkn)->key, (*tkn)->val))
		return (shell_err(1, "Error: groups_and_group_to_args()", 0, 2));
	if (tcmd->subsh_lvl > 0)
		return (EXIT_SUCCESS);
	return (groups_and_group_to_args2(tkn, tcmd));
}

//
//add cmds tkns after pipes only if there is no syntax error
//
//skip all tkn that are not a pipe, check syntax - tokens must follow pipe
//move to a token after pipe if syntax is ok and repeat until no tkns left
//
static int	args_and_tcmd_with_pipes_to_cmds(t_lst *expanded, t_lst *cmds)
{
	t_key_val_lst	*curr;
	int				subsh_lvl;

	subsh_lvl = 0;
	curr = expanded->head;
	while (curr)
	{
		if (args_and_tcmd_info_to_cmds(curr, cmds))
			return (EXIT_FAILURE);
		while (curr && (*(int *)&curr->key != LEX_KEY_PIPE || subsh_lvl != 0))
		{
			subsh_lvl += (*(int *)&curr->key == LEX_KEY_PARN_L);
			subsh_lvl -= (*(int *)&curr->key == LEX_KEY_PARN_R);
			curr = curr->next;
		}
		if (curr && !(curr->next))
			return (shell_err(1, ERR_PRS_PIPE, 0, 2));
		if (curr)
			curr = curr->next;
	}
	return (EXIT_SUCCESS);
}

//
//execute_tlst_cmds(groups, info)
//t_key_val_lst	*ptr = groups->head; (ptr to tlst groups kv)
//exec_one_group(*(int *)&ptr->key, ptr->val, info) - key type val tlst group
//set_texecgroup_cmds(expanded, cmds)
//args_and_tcmd_with_pipes_to_cmds(t_lst *expanded, t_lst *cmds)
//t_key_val_lst	*curr = expanded->head; (ptr to tlst group)
//args_and_tcmd_info_to_cmds(curr, cmds)
//groups_and_group_to_args(t_key_val_lst **c, t_cmd_info *info, t_lst *args)
//add_node(args, (*c)->key, (*c)->val)
//

int	set_texecgroup_cmds(t_lst *expanded, t_exec_group *cmds)
{
	if (cmds->type & CMD_TYPE_PIPE)
		return (args_and_tcmd_with_pipes_to_cmds(expanded, cmds->cmds));
	return (args_and_tcmd_info_to_cmds(expanded->head, cmds->cmds));
}
