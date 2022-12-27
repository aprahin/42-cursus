/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 06:07:21 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/26 14:25:51 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

//your point of entry good sir
//you know it :)
pid_t	executor(t_exec_group *cmds, t_shell *info)
{
	int	pid;

	if (CMD_TYPE_PIPE & cmds->type)
		return (execute_pipe(cmds, info));
	else if (((t_cmd_info *)cmds->cmds->head->val)->type & CMD_TO_SUBSH)
	{
		pid = fork();
		if (pid < 0)
			return (-1);
		if (pid != 0)
			return (pid);
		signal(SIGQUIT, SIG_DFL);
		execute_subshell(cmds->cmds->head, info);
	}
	else
		return (execute_bb(cmds, info));
	return (-1);
}

int	is_builtin(t_key_val_lst *cmd, t_shell *info)
{
	t_lst		*elems;
	int			i;

	i = -1;
	elems = cmd->key;
	while (++i < 7)
		if (!ft_strncmp(elems->head->val,
				info->built_in_names[i], ft_strlen(elems->head->val) + 1))
			return (i);
	return (i);
}

//
//to be launched with cmds_node: t_key_val_lst *cmd  = cmds->cmds->head;
//
//make argv to be used by execve() to exec binary
//populate it with absolute filepath of cmd and args values
//
int	make_execve_argv(t_key_val_lst *cmd, char ***argv, char *path)
{
	t_key_val_lst		*args_cursor;
	t_lst				*args;
	int					i;

	i = 0;
	args = cmd->key;
	*argv = hmalloc(sizeof(char *) * (args->size + 1));
	if (!(*argv))
		shell_err(1, "Error: make_execve_argv()", 1, 0);
	args_cursor = args->head->next;
	(*argv)[i++] = ft_strdup(path);
	while (args_cursor)
	{
		(*argv)[i] = ft_strdup((char *)(args_cursor->val));
		if (!(*argv)[i] && !hfree2darr_upto_idx(*argv, i))
			shell_err(1, "Error: make_execve_argv()", 1, 0);
		args_cursor = args_cursor->next;
		i++;
	}
	(*argv)[i] = NULL;
	return (EXIT_SUCCESS);
}

//
//constructs absolute path to be used by execve() to exec bin
//checks access rights while making an absolute path
//
static int	get_absolute_path(char **filepaths, char	**fp, t_lst *elems)
{
	int		i;
	char	*to_hfree;
	char	*prev;

	i = -1;
	prev = NULL;
	while (filepaths[++i] && ft_strlen(elems->head->val) != 0)
	{
		to_hfree = filepaths[i];
		filepaths[i] = strjoin_with_delimeter(filepaths[i],
				elems->head->val, '/');
		hfree(to_hfree);
		if (!filepaths[i])
			return (shell_err(1, "Error: get_absolute_path()", 1, 0));
		if (!access(filepaths[i], F_OK))
			prev = filepaths[i];
		if (!access(filepaths[i], X_OK))
		{
			*fp = ft_strdup(filepaths[i]);
			hfree2darr_upto_idx(filepaths, -1);
			return (EXIT_SUCCESS);
		}
	}
	return (1 + (prev != NULL));
}

//
//to be launched with cmds_node: t_key_val_lst *cmd  = cmds->cmds->head;
//
//produces absolute pathname to be used with execve() to exec binary
//absolute pathname is also used by make_execve_argv()
//
//writes produces absolute pathname to the char **filepath
//if no file cannot be accessed exits
//
//use with get_val(info->envp_list, "PATH") as char *path
//
//access() checks whether the calling process can access the file
//pathname.  If pathname is a symbolic link, it is dereferenced.
//
// return (shell_err(1, "Error: file not found", 0, 127));
//return (shell_err(1, "Error: permission denied", 0, 126));
//return (shell_err(1, "Error: permission denied", 0, 126));
//return (shell_err(1, "Error: command not found", 0, 127));
int	access_cmd_file(t_key_val_lst *cmd, char *path, char **filepath)
{
	char		**filepaths;
	t_lst		*elems;
	int			flag;

	elems = cmd->key;
	if (ft_strchr(elems->head->val, '/') || !path)
	{
		*filepath = ft_strdup((char *)(elems->head->val));
		if (check_file_not_dir(*filepath) != 0)
			return (1);
		if (access(*filepath, F_OK) == 0 && access(*filepath, X_OK))
			return (named_err(ERR_SH, *filepath, ERR_PERMS, 126), 1);
		return (EXIT_SUCCESS);
	}
	filepaths = ft_split(path, ':');
	if (!filepaths)
		shell_err(1, "Error: hmalloc error access_cmd_file()", 1, 0);
	flag = get_absolute_path(filepaths, filepath, elems);
	if (!flag)
		return (EXIT_SUCCESS);
	hfree2darr_upto_idx(filepaths, -1);
	*filepath = NULL;
	if (flag == 2)
		return (named_err(ERR_SH, *filepath, ERR_PERMS, 126), 1);
	return (named_err(ERR_SH, elems->head->val, ERR_CMD, 127), 1);
}
