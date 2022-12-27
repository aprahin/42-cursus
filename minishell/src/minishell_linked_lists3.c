/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_linked_lists3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:07:12 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 12:32:21 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_linked_lists.h"

//
//used by exec_one_group()
//if new_tlst for either cmds or files failed - hfree the group
//
t_exec_group	*new_texec_group(int type)
{
	t_exec_group		*texecgroup;

	texecgroup = (t_exec_group *)hmalloc(sizeof(t_exec_group));
	if (!texecgroup)
		return (NULL);
	texecgroup->type = type;
	texecgroup->cmds = new_tlst(NULL, hfree_voidptr_lst, hfree);
	texecgroup->heredoc_files_names = new_tlst(NULL, NULL, hfree);
	if (!texecgroup->cmds || !texecgroup->heredoc_files_names)
	{
		if (texecgroup->cmds)
			hfree_tlst(texecgroup->cmds);
		if (texecgroup->heredoc_files_names)
			hfree_tlst(texecgroup->heredoc_files_names);
		hfree(texecgroup);
		return (NULL);
	}
	return (texecgroup);
}

//
//val for cmds_group is 
//unlink() - delete a name and possibly the file it refers to
//
void	hfree_texec_group(void *group)
{
	t_key_val_lst	*ptr;

	ptr = ((t_exec_group *)group)->heredoc_files_names->head;
	while (ptr)
	{
		unlink(ptr->val);
		ptr = ptr->next;
	}
	hfree_tlst(((t_exec_group *)group)->cmds);
	hfree_tlst(((t_exec_group *)group)->heredoc_files_names);
	hfree(group);
}

//
//t_dstr_key_f 
//
void	hfree_voidptr_lst(void *llist)
{
	hfree_tlst((t_lst *)llist);
}

//	
//t_dstr_key_f
//hfree() only hfrees the cursor to the starting pair of a lst
//
void	hfree_tlst(t_lst *list)
{
	t_key_val_lst	*elem;
	t_key_val_lst	*elem_next;

	if (!list)
		return ;
	elem = list->head;
	while (elem)
	{
		elem_next = elem->next;
		if (list->dstr_k)
			list->dstr_k(elem->key);
		if (list->dstr_v)
			list->dstr_v(elem->val);
		hfree(elem);
		elem = elem_next;
	}
	hfree(list);
}
