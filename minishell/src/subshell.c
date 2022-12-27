/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:21:25 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/25 15:00:14 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

// execute subshell NOT by forking
pid_t	execute_subshell(t_key_val_lst *cmd_ptr, t_shell *info)
{
	int		fd[2];

	if (access_files(cmd_ptr->val) != 0)
		exit(1);
	open_files(cmd_ptr->val, &(fd[0]), &(fd[1]));
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	prs_and_exec(cmd_ptr->key, info);
	hobliterate();
	exit(get_g_last_exit());
	return (shell_err(-1, "execute_subshell(): couldn't exit", 0, 1));
}
