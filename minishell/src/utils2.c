/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:53:26 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 11:38:57 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**hfree_2darr(char **str2, int j)
{
	int		i;

	i = 0;
	while (i < j)
		hfree(str2[i++]);
	hfree(str2);
	return (NULL);
}

int	hfree_tshell(t_shell *info)
{
	hfree2darr_upto_idx(info->envp, -1);
	hfree(info->g_last_exit_str);
	hfree_tlst(info->envp_state);
	rl_clear_history();
	return (EXIT_SUCCESS);
}

int	hfree_texecgroup_and_tlst(t_exec_group *group, t_lst *expanded)
{
	hfree_texec_group(group);
	hfree_tlst(expanded);
	return (-1);
}

int	get_in_fd(t_cmd_info *info)
{
	if (!info->file_in)
		return (STDIN_FILENO);
	return (open(info->file_in, O_RDONLY, 0644));
}

int	get_out_fd(t_cmd_info *info)
{
	if (!info->file_out)
		return (STDOUT_FILENO);
	if (CMD_TO_APPEND & info->type)
		return (open(info->file_out, O_CREAT | O_WRONLY | O_APPEND, 0644));
	return (open(info->file_out, O_CREAT | O_WRONLY, 0644));
}
