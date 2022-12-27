/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:08:29 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/25 01:54:24 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

// I wonder if I should open and immediately close in_fd for builtins...

char	*whereami(void)
{
	char	*buf;
	char	*dir;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
		return (shell_err(0, NULL, 1, 1), NULL);
	dir = ft_strdup(buf);
	free(buf);
	return (dir);
}

int	cd_home(t_shell *info)
{
	t_key_val_lst	*envp;
	char			*home;

	envp = info->envp_state->head;
	home = NULL;
	while (envp)
	{
		if (ft_strncmp("HOME", (char *) envp->key, 5) == 0)
		{
			home = envp->val;
			break ;
		}
		envp = envp->next;
	}
	if (home == NULL)
		return (shell_err(EXIT_FAILURE, ERR_CD_HOME, 0, 1));
	if (chdir(home) != 0)
		return (shell_err(EXIT_FAILURE, ERR_CD_CD, 0, 1));
	return (EXIT_SUCCESS);
}

int	builtin_cd(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd)
{
	t_key_val_lst	*arg_ptr;
	char			*dir;

	(void) out_fd;
	arg_ptr = get_arg_ptr(cmd_ptr)->next;
	if (get_argc(cmd_ptr) == 1)
		return (cd_home(info));
	else if (get_argc(cmd_ptr) > 2)
		return (shell_err(EXIT_FAILURE, ERR_CD_ARG, 0, 1));
	dir = arg_ptr->val;
	if (dir[0] != '/')
	{
		dir = ft_strjoin("/", dir);
		dir = ft_strjoin(whereami(), dir);
	}
	if (chdir(dir) != 0)
		return (shell_err(EXIT_FAILURE, ERR_CD_CD, 0, 1));
	return (EXIT_SUCCESS);
}

// !!! should check for write errors in ft_put..._fd !!!  
// nl: X1 for newline, X0 for no newline 
// 0X for still hasn't met an argument, 1X for have met an argument
int	builtin_echo(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd)
{
	t_key_val_lst	*arg_ptr;
	int				nl;

	arg_ptr = get_arg_ptr(cmd_ptr)->next;
	nl = 0b01;
	while (arg_ptr)
	{
		if (ft_strncmp("-n", arg_ptr->val, 3) == 0 && !(nl & 0b10))
			nl = 0b00;
		else
		{
			nl |= 0b10;
			if (write(out_fd, arg_ptr->val, ft_strlen(arg_ptr->val)) < 0)
				return (shell_err(EXIT_FAILURE, ERR_ECHO_WR, 0, 1));
		}
		arg_ptr = arg_ptr->next;
		if ((nl & 0b10) && arg_ptr)
		{
			if (write(out_fd, " ", 1) < 0)
				return (shell_err(EXIT_FAILURE, ERR_ECHO_WR, 0, 1));
		}
	}
	if (nl & 0b01)
		ft_putchar_fd('\n', out_fd);
	return ((void) info, EXIT_SUCCESS);
}

int	builtin_pwd(t_key_val_lst *cmd_ptr, t_shell *info, int out_fd)
{
	char	*buf;
	char	*dir;

	(void) info;
	(void) cmd_ptr;
	buf = getcwd(NULL, 0);
	if (buf == NULL)
		return (shell_err(EXIT_FAILURE, NULL, 1, 1));
	dir = ft_strdup(buf);
	free(buf);
	if (write(out_fd, dir, ft_strlen(dir)) < 0)
		return (shell_err(EXIT_FAILURE, ERR_PWD_WR, 0, 1));
	if (write(out_fd, "\n", 1) < 0)
		return (shell_err(EXIT_FAILURE, ERR_PWD_WR, 0, 1));
	return (EXIT_SUCCESS);
}
