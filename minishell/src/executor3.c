/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:42:11 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/21 20:5 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

// check if the infile exists and is accessible
// check if the outfile exists and is accessible, or create it with -rw-r--r--
int	access_files(t_cmd_info *info)
{
	int	tmp;

	if (info->file_in)
	{
		if (access(info->file_in, F_OK != 0))
			return (named_err(ERR_SH, info->file_in, ERR_FILE, 1), 1);
		else if (access(info->file_in, R_OK) != 0)
			return (named_err(ERR_SH, info->file_in, ERR_PERMS, 1), 1);
	}
	if (info->file_out)
	{
		if (access(info->file_out, F_OK != 0))
		{
			tmp = open(info->file_out, O_CREAT, 0644);
			if (tmp < 0)
				return (named_err(ERR_SH, info->file_out, ERR_CREAT, 1), 1);
			if (close(tmp) != 0)
				return (named_err(ERR_SH, info->file_out, ERR_CLOSE, 1), 1);
		}
		else if (access(info->file_out, W_OK) != 0)
			return (named_err(ERR_SH, info->file_out, ERR_PERMS, 1), 1);
	}
	return (0);
}

// execute builtin NOT by forking
pid_t	execute_builtin(t_key_val_lst *cmd_ptr, t_shell *info)
{
	int	ret;
	int	out_fd;

	open_files(cmd_ptr->val, NULL, &out_fd);
	ret = (*(info->built_in_f)[is_builtin(cmd_ptr, info)])
		(cmd_ptr, info, out_fd);
	close(out_fd);
	set_g_last_exit(ret);
	return (1);
}

pid_t	fork_binary(t_key_val_lst *cmd_ptr, t_shell *info, char *filepath)
{
	int		pid;
	char	**args;
	int		fd[2];

	pid = fork();
	if (pid < 0)
		return (shell_err(-1, "fork_binary(): failed to fork", 0, 1));
	else if (pid != 0)
		return (pid);
	signal(SIGQUIT, SIG_DFL);
	if (make_execve_argv(cmd_ptr, &args, filepath) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	open_files(cmd_ptr->val, &(fd[0]), &(fd[1]));
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (info->update_envp)
		update_tshell_envp(info);
	execve(filepath, args, info->envp);
	shell_err(-1, "minihell: command not found", 0, 1);
	return (hobliterate(), exit(127), -1);
}

// execute binary by forking if the command exists
pid_t	execute_binary(t_key_val_lst *cmd_ptr, t_shell *info)
{
	t_key_val_lst	*envp;
	char			*filepath;
	char			*path;
	int				ret;

	path = NULL;
	envp = info->envp_state->head;
	while (envp)
	{
		if (ft_strncmp("PATH", envp->key, 5) == 0)
		{
			path = ft_strdup(envp->val);
			break ;
		}
		envp = envp->next;
	}
	ret = access_cmd_file(cmd_ptr, path, &filepath);
	if (ret != 0)
		return (ret);
	return (fork_binary(cmd_ptr, info, filepath));
}

// execute binary or built-in routine, return last executed process
pid_t	execute_bb(t_exec_group *cmds, t_shell *info)
{
	if (access_files(cmds->cmds->head->val) != 0)
		return (0);
	if (is_builtin(cmds->cmds->head, info) < 7)
		return (execute_builtin(cmds->cmds->head, info));
	else
		return (execute_binary(cmds->cmds->head, info));
	return (1);
}
