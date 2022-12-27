/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:27:19 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/25 02:07:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

// Allocates an envp from envp_state to envp variable
int	generate_envp(t_shell *info, char ***envp)
{
	t_key_val_lst	*ptr;
	int				i;

	ptr = info->envp_state->head;
	i = 0;
	*envp = hmalloc((info->envp_state->size + 1) * sizeof(char *));
	if (*envp == NULL)
		return (shell_err(1, "generate_envp(): hmalloc failed", 1, 1));
	while (ptr)
	{
		(*envp)[i] = strjoin_with_delimeter(ptr->key, ptr->val, '=');
		++i;
		ptr = ptr->next;
	}
	(*envp)[i] = NULL;
	return (EXIT_SUCCESS);
}

//feel hfree to remove adjust to your needs
static char	**new_envp_from_envp_state(t_lst *envp_state)
{
	char			**envp;
	unsigned int	i;
	t_key_val_lst	*ptr;

	envp = (char **)hmalloc(sizeof(char *) * (envp_state->size + 1));
	if (!envp)
		return (NULL);
	i = 0;
	ptr = envp_state->head;
	envp[envp_state->size] = NULL;
	while (i < envp_state->size)
	{
		envp[i] = strjoin_with_delimeter(ptr->key, ptr->val, '=');
		if (!envp[i])
			return (hfree_2darr(envp, i));
		ptr = ptr->next;
		++i;
	}
	return (envp);
}

//feel hfree to remove adjust to your needs
//
//before using execve (and make_execve_argv() access_cmd_file())
//update_tshell_envp() when is t_shell char 
//update_envp flag is set before using execve()
//
int	update_tshell_envp(t_shell *info)
{
	hfree2darr_upto_idx(info->envp, -1);
	info->envp = new_envp_from_envp_state(info->envp_state);
	if (!(info->envp))
		return (shell_err(-1, "Error: update_tshell_envp()", 1, 0));
	info->update_envp = 0;
	return (EXIT_SUCCESS);
}

// open outfile with correct permissions based on type
// returns fd
int	open_outfile(char *file, int type)
{
	struct stat	file_stat;

	if (access(file, F_OK) == 0 && stat(file, &file_stat) != 0)
		return (shell_err(-1, "open_outfile(): couldn't get stat", 0, 1));
	else
		file_stat.st_mode = 0644;
	if ((type & CMD_TO_APPEND) == 0)
		return (open(file, O_WRONLY | O_CREAT | O_TRUNC, file_stat.st_mode));
	else if (type & CMD_TO_APPEND)
		return (open(file, O_WRONLY | O_CREAT | O_APPEND, file_stat.st_mode));
	return (-1);
}

// open and set fd for in_fd out_fd if they aren't nullptr;
// default values if no files set: STDIN and STDOUT
int	open_files(t_cmd_info *info, int *in_fd, int *out_fd)
{
	if (in_fd)
		*in_fd = dup(STDIN_FILENO);
	if (out_fd)
		*out_fd = dup(STDOUT_FILENO);
	if (in_fd && info->file_in)
	{
		close(*in_fd);
		*in_fd = open(info->file_in, O_RDONLY);
		if (*in_fd < 0)
			return (1);
	}
	if (out_fd && info->file_out)
	{
		close(*out_fd);
		*out_fd = open_outfile(info->file_out, info->type);
		if (*out_fd < 0)
			return (1);
	}
	return (0);
}
