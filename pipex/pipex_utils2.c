/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:55:00 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/05 11:22:27 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	readhd(char *lim, int infd, int outfd)
{
	char	*nl;
	char	*tmp;

	while (1)
	{
		nl = get_next_line(infd);
		if (!nl)
			return ;
		tmp = ft_strtrim(nl, "\n");
		if (ft_strncmp(tmp, lim, ft_strlen(lim) + 1) == 0)
		{
			free(tmp);
			free(nl);
			return ;
		}
		ft_putstr_fd(nl, outfd);
		free(tmp);
		free(nl);
	}
}

void	exiterr(char *msg)
{
	perror(msg);
	exit(0);
}

void	writeout(char *name, char *infile, int infd)
{
	int		outfd;
	char	b[1];

	if (ft_strncmp(infile, "here_doc", 9) == 0)
		outfd = open(name, O_RDWR | O_CREAT | O_APPEND, 0777);
	else
	{
		if (access(name, F_OK) == 0)
			unlink(name);
		outfd = open(name, O_RDWR | O_CREAT, 0666);
	}
	if (outfd < 0)
		exiterr("writeout (2)");
	if (infd < 0)
		exiterr("writeout (3)");
	while (read(infd, b, sizeof(char)) > 0)
		write(outfd, b, sizeof(char));
	if (close(infd) != 0)
		exiterr("writeout (4)");
}

void	resetpipe(int (*p)[2])
{
	if (close((*p)[1]) != 0)
		exiterr("resetpipe (1)");
	if (close((*p)[0]) != 0)
		exiterr("resetpipe (2)");
	pipe(*p);
}

void	closefds(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 > 0 && close(fd1) != 0)
		exiterr("closefds (1)");
	if (fd2 > 0 && close(fd2) != 0)
		exiterr("closefds (2)");
	if (fd3 > 0 && close(fd3) != 0)
		exiterr("closefds (3)");
	if (fd4 > 0 && close(fd4) != 0)
		exiterr("closefds (4)");
}
