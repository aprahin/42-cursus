/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_linked_lists4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:07:12 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 11:38:57 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell_linked_lists.h"

t_key_val_lst	*get_next_tkn(t_key_val_lst *curr)
{
	if (!curr)
		return (NULL);
	curr = curr->next;
	while (curr && curr->key == LEX_KEY_SEP)
		curr = curr->next;
	return (curr);
}

void	hmalloc_t_cmd_info(t_cmd_info **info)
{
	*info = hmalloc(sizeof(t_cmd_info));
	if (!(*info))
		return ;
	(*info)->file_in = NULL;
	(*info)->file_out = NULL;
	(*info)->type = 0;
	(*info)->subsh_lvl = 0;
}

int	hfree_tlst_ret0(t_lst *str)
{
	hfree_tlst(str);
	return (EXIT_SUCCESS);
}

int	hfree_tlst_ret1(t_lst *groups)
{
	hfree_tlst(groups);
	return (EXIT_FAILURE);
}
