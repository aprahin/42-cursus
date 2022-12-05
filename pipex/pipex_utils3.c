/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:55:40 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/05 15:36:12 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	setinfile(char	**argv, int *infd, int (*p)[2])
{
	*infd = open(argv[1], O_RDWR);
	if (*infd < 0)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (*infd >= 0)
			readhd(argv[2], *infd, (*p)[1]);
		return (1);
	}
	else
	{
		if (*infd >= 0)
			(*p)[0] = *infd;
		return (0);
	}
}

void	birthodd(char *name, char **env, int (*ep)[2], int (*op)[2])
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exiterr("birthodd (1)");
	if (pid == 0)
	{
		closefds((*op)[1], (*ep)[0], -1, -1);
		execute(name, (*op)[0], (*ep)[1], env);
	}
	else
		resetpipe(op);
}

void	birtheven(char *name, char **env, int (*ep)[2], int (*op)[2])
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exiterr("birtheven (1)");
	if (pid == 0)
	{
		closefds((*ep)[1], (*op)[0], -1, -1);
		execute(name, (*ep)[0], (*op)[1], env);
	}
	else
		resetpipe(ep);
}

void	waitchildren(int i)
{
	extern int	g_ex;
	int			e;

	while (i-- > 0)
	{
		wait(&e);
		if (g_ex != 128)
			g_ex = WEXITSTATUS(e);
	}
	if (g_ex == 128)
		g_ex = 127;
}

void	checkargc(int count)
{
	char	*msg;

	msg = "checkargc (1): missing arguments (needed at least 4)\n";
	if (count < 5)
	{
		ft_putstr_fd(msg, STDERR_FILENO);
		exit(1);
	}
}
