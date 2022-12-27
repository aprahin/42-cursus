/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:26:02 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/25 11:38:57 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

// return an array such as 
// STDIN->pipe0write->pipe0read->...->pipeNwrite->pipeNread->STDOUT
int	*open_pipes(t_exec_group *cmds)
{
	int		*ret;
	t_ui	i;
	int		tmp[2];

	ret = hmalloc((cmds->cmds->size * 2) * sizeof(int));
	if (ret == NULL)
	{
		shell_err(0, "open_pipes(): hmalloc failed", 1, 1);
		return (NULL);
	}
	ret[0] = STDIN_FILENO;
	ret[cmds->cmds->size * 2 - 1] = STDOUT_FILENO;
	i = 0;
	while (++i < cmds->cmds->size * 2 - 1)
	{
		pipe(tmp);
		ret[i] = tmp[1];
		ret[++i] = tmp[0];
	}
	return (ret);
}

// dup2 using pipes, or infiles outfiles if they exit
int	dup_open_files(t_cmd_info *info, int *pipes)
{
	int	in_fd;
	int	out_fd;

	if (open_files(info, &in_fd, &out_fd) != 0)
		return (1);
	if (info->file_in)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	else
		dup2(*pipes, STDIN_FILENO);
	if (info->file_out)
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
	else
		dup2(*(pipes + 1), STDOUT_FILENO);
	return (0);
}

// close every fd in pipes except for STDIN and STDOUT
void	close_pipes(int *pipes)
{
	int	i;

	i = 1;
	while (*pipes != STDIN_FILENO)
		pipes--;
	while (pipes[i] != STDOUT_FILENO)
		close(pipes[i++]);
	return ;
}
