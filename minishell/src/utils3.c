/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:28:53 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 15:54:06 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// writes a custom error message consisting of start-name-end, and sets
// global exit to g_e
void	named_err(const char *start, const char *name,
	const char *end, int g_e)
{
	char	*msg;

	set_g_last_exit(g_e);
	if (name == NULL)
		return ;
	msg = ft_strdup((char *) name);
	if (start != NULL)
		msg = ft_strjoin(start, msg);
	if (end != NULL)
		msg = ft_strjoin(msg, end);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}

int	update_g_last_exit(t_shell *info)
{
	hfree(info->g_last_exit_str);
	info->g_last_exit_str = ft_itoa(get_g_last_exit());
	if (!info->g_last_exit_str)
		return (shell_err(1, "Error: update_g_last_exit()", 1, 0));
	return (EXIT_SUCCESS);
}

char	*strjoin_with_delimeter(const char *s1, const char *s2, char d)
{
	const int	size = ft_strlen(s1) + ft_strlen(s2) + 2;
	char		*res;
	int			i;

	res = (char *)hmalloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		res[i++] = *s1++;
	res[i++] = d;
	while (s2 && *s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

// turns every wildcard (*) that is in quotes or doubles quotes into a
// char with value -42
int	wc_to_42(char **str)
{
	int	i;
	int	single_q;
	int	double_q;

	i = 0;
	single_q = 0;
	double_q = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\'')
			single_q = !single_q;
		else if ((*str)[i] == '\"')
			double_q = !double_q;
		else if ((*str)[i] == '*' && (single_q || double_q))
			(*str)[i] = -42;
		++i;
	}
	return (0);
}
