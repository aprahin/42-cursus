/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:25:12 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/03 20:25:13 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	g_ex = 0;

void	noexec(char *name)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	hd;
	int	infd;
	int	epipe[2];
	int	opipe[2];

	checkargc(argc);
	pipe(opipe);
	pipe(epipe);
	hd = setinfile(argv, &infd, &epipe);
	i = -1;
	while (++i < argc - 3 - hd)
	{
		if (i % 2)
			birthodd(argv[i + 2 + hd], env, &epipe, &opipe);
		else
			birtheven(argv[i + 2 + hd], env, &epipe, &opipe);
	}
	closefds(opipe[1], epipe[1], -1, -1);
	waitchildren(argc - 3 - hd);
	if (!((argc - hd) % 2))
		writeout(argv[argc - 1], argv[1], opipe[0]);
	else
		writeout(argv[argc - 1], argv[1], epipe[0]);
	return (g_ex);
}
