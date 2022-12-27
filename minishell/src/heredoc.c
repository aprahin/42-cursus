/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:05:42 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 16:41:47 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/executor.h"

static int	hfree_heredoc(const char *msg, char *f, char *s, int fd)
{
	if (msg && f)
		hfree(f);
	if (s)
		hfree(s);
	if (fd != -1)
		close(fd);
	if (msg)
		return (shell_err(1, msg, 1, 0));
	return (EXIT_SUCCESS);
}

static int	add_fname_to_heredoc_fns(char *f, t_cmd_info *info,
		t_lst *heredoc_files_names)
{
	if (add_node(heredoc_files_names, 0, f))
		return (EXIT_FAILURE);
	info->delimiter = info->file_in;
	info->file_in = f;
	return (!(info->file_in));
}

static int	write_heredoc_to_fd(t_cmd_info *c_info, int fd)
{
	char	*str;

	while (1)
	{
		str = readline("> ");
		if (!str || !(ft_strncmp(str, c_info->delimiter, ft_strlen(str) + 1)))
			break ;
		if (write(fd, str, ft_strlen(str)) == -1)
			return (EXIT_FAILURE);
		if (write(fd, "\n", 1) == -1)
			return (EXIT_FAILURE);
		hfree(str);
	}
	hfree(str);
	return (EXIT_SUCCESS);
}

//
//fork() creates a new process by duplicating the calling process.
//On failure, -1 is returned in the parent
//On success 0 is returned to child, and child_pid is returned to parent
//sighandler_t signal(int signum, sighandler_t handler);
//SIG_IGN - ignore the signal
//SIGINT (“program interrupt”) the user typed the INTR character (C-c)
//SIGQUIT is similar to SIGINT, but it’s controlled by the QUIT character (C-\)
//waitpid() suspends execution of the 
// calling process until specified pid has changed state
//
static int	execute_heredoc(t_cmd_info *c_info, int fd)
{
	int		pid;
	int		sig;

	sig = 0;
	pid = fork();
	if (pid == -1)
		return (shell_err(1, "Error: execute_heredoc()", 1, 0));
	if (pid)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		waitpid(pid, &sig, 0);
	}
	if (!pid)
	{
		signal(SIGINT, sig_heredoc_handler);
		signal(SIGQUIT, SIG_IGN);
		if (write_heredoc_to_fd(c_info, fd))
		{
			hobliterate();
			exit(shell_err(1, "Error: execute_heredoc()", 1, 0));
		}
		return (hobliterate(), exit(EXIT_SUCCESS), 1);
	}
	return (WEXITSTATUS(sig) != 0);
}

//
//The resultant text is placed in a temp file,
//which is given to the command as stdin.
//access() checks whether the calling process can access the file  pathname
//unlink() deletes a name from the filesystem. On error, -1 is returned
//read() flags
//O_CREAT If pathname does not exist, create it as a regular file.
//O_WRONLY File access mode write only
//0644 -rw-r--r-- User: read & write Group: read  Other: read
//
int	create_heredoc(t_cmd_info *c_info, t_lst *heredoc_files_names)
{
	int		fd;
	char	*f;
	char	*s;

	s = ft_uitoa(heredoc_files_names->size);
	fd = -1;
	if (!s)
		return (hfree_heredoc("Error: create_heredoc() itoa", NULL, s, fd));
	f = ft_strjoin("/var/tmp/minishell.tmp.", s);
	if (!f)
		return (hfree_heredoc("Error: create_heredoc() hmalloc", f, s, fd));
	if (!(access(f, F_OK)) && unlink(f) == -1)
		return (hfree_heredoc(ERR_HD_EXIST, f, s, fd));
	fd = open(f, O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		return (hfree_heredoc("Error: create_heredoc() open", f, s, fd));
	if (add_fname_to_heredoc_fns(f, c_info, heredoc_files_names))
		return (hfree_heredoc("Error: add_fname_to_heredoc_fns()", f, s, fd));
	if (execute_heredoc(c_info, fd))
	{
		close(fd);
		hfree(s);
		return (2);
	}
	return (hfree_heredoc(NULL, f, s, fd));
}
