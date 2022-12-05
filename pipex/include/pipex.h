/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:19:51 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/05 15:36:19 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"

// open
# include <fcntl.h>

// close, read, write, access, dup, dup2, execve, exit, fork, pipe, unlink
# include <unistd.h>

// malloc, free
# include <stdlib.h>

// perror
# include <stdio.h>

// strerror
# include <string.h>

// wait, waitpid
# include <sys/wait.h>

int		countquote(char *str);
char	*escquote(char *str);
char	**getpath(char **env);
char	*getexec(char *name, char **path);
void	execute(char *bin, int infd, int outfd, char **env);
void	readhd(char *lim, int infd, int outfd);
void	exiterr(char *msg);
void	writeout(char *name, char *infile, int infd);
void	resetpipe(int (*p)[2]);
void	closefds(int fd1, int fd2, int fd3, int fd4);
int		setinfile(char	**argv, int *infd, int (*p)[2]);
void	birthodd(char *name, char **env, int (*ep)[2], int (*op)[2]);
void	birtheven(char *name, char **env, int (*ep)[2], int (*op)[2]);
void	waitchildren(int i);
void	checkargc(int count);
void	noexec(char *name);

#endif