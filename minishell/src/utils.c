/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:53:26 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 11:33:08 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h" 

int	shell_err(int ret, const char *msg, char liberr, int g_e)
{
	if (msg && *msg && !liberr)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, "\n", 1);
		set_g_last_exit(g_e);
		return (ret);
	}
	if (errno && liberr)
	{
		if (msg && *msg)
			perror(msg);
		else
			perror("Error: ");
		set_g_last_exit(1);
	}
	return (ret);
}

char	**hmalloc2darr_upto_idx(int m, int n)
{
	int		i;
	char	**arr;

	if (!m || !n)
		return (NULL);
	arr = (char **)hmalloc(sizeof(char *) * m);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < m)
	{
		arr[i] = (char *)hmalloc(sizeof(char *) * n);
		if (!arr[i])
			return (hfree2darr_upto_idx(arr, i));
	}
	return (arr);
}

void	*hfree2darr_upto_idx(char **arr, int m)
{
	int		i;

	if (!arr)
		return (NULL);
	i = 0;
	if (m == -1)
	{
		while (arr[i])
			hfree(arr[i++]);
		hfree(arr);
		return (NULL);
	}
	while (i < m)
		hfree(arr[i++]);
	hfree(arr);
	return (NULL);
}

char	*ft_uitoa(t_ui n)
{
	char			*s;
	t_ui			cnt;
	t_ui			i;

	cnt = 0;
	i = n;
	while (i)
	{
		++cnt;
		i /= 10;
	}
	if (!cnt)
		cnt = 1;
	s = (char *)hmalloc(sizeof(char) * (cnt + 1));
	if (!s)
		return (NULL);
	s[cnt] = '\0';
	while (cnt--)
	{
		s[cnt] = '0' + n % 10;
		n /= 10;
	}
	return (s);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\f');
}
