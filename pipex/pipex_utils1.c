/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:54:41 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/05 11:59:54 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	countquote(char *str)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (str[++i])
	{
		if (str[i + 1] && str[i] == '\\'
			&& (str[i + 1] == '"' || str[i + 1] == '\''))
			continue ;
		++n;
	}
	return (n);
}

char	*escquote(char *str)
{
	int		i;
	int		n;
	char	*esc;

	esc = malloc((countquote(str) + 1) * sizeof(char));
	if (!esc)
		return (0);
	i = -1;
	n = 0;
	while (str[++i])
	{
		if (str[i + 1] && str[i] == '\\'
			&& (str[i + 1] == '"' || str[i + 1] == '\''))
			continue ;
		esc[n++] = str[i];
	}
	esc[n] = '\0';
	free(str);
	return (esc);
}

char	**getpath(char **env)
{
	int		i;
	char	*path;
	char	**split;

	i = -1;
	path = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_strdup(env[i]);
			break ;
		}
	}
	if (!path)
		return (0);
	split = ft_split(path + 5, ':');
	free(path);
	i = -1;
	while (split[++i])
		split[i] = ft_strjoinf(split[i], "/", 1, 0);
	return (split);
}

char	*getexec(char *name, char **path)
{
	int		i;
	char	*ret;

	i = -1;
	ret = NULL;
	if (ft_strncmp(name, "./", 2) == 0
		&& access(name, R_OK & X_OK & F_OK) == 0)
		return (ft_strdup(name));
	else if (ft_strncmp(name, "./", 2) != 0)
	{
		while (path[++i])
		{
			ret = ft_strjoin(path[i], name);
			if (access(ret, R_OK & X_OK & F_OK) == 0)
				return (ret);
			free(ret);
			ret = NULL;
		}
	}
	if (!ret && ft_strchr(name, '/')
		&& access(name, R_OK & X_OK & F_OK) == 0)
		return (ft_strdup(name));
	return (0);
}

void	execute(char *bin, int infd, int outfd, char **env)
{
	int		i;
	char	**path;
	char	**args;
	char	*exec;

	path = getpath(env);
	args = ft_split(bin, ' ');
	dup2(infd, STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	closefds(infd, outfd, -1, -1);
	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '\'')
			args[i] = ft_strtrim(args[i], "\'");
		else if (args[i][0] == '\"')
			args[i] = ft_strtrim(args[i], "\"");
		args[i] = escquote(args[i]);
	}
	exec = getexec(args[0], path);
	if (exec)
		execve(exec, args, env);
	else
		noexec(bin);
}
