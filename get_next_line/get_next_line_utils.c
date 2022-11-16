/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:53:59 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/16 11:56:42 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(int count, int size)
{
	void			*array;
	unsigned char	*p;
	void			*s;
	int				len;

	len = count * size;
	if (count == 0 || size == 0)
	{
		s = malloc(1);
		return (s);
	}
	array = malloc(len);
	if (!array)
		return (0);
	p = array;
	while (len > 0)
	{
		*p = 0;
		p++;
		len--;
	}
	return (array);
}

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

int	getnl(const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

char	*trimtonl(char **s)
{
	char	*t;
	char	*u;
	int		l;
	int		i;

	if (!s)
		return (0);
	i = 0;
	l = getnl(*s) + 1;
	u = ft_calloc(l + 1, sizeof(char));
	if (!u)
		return (0);
	while (l--)
		u[l] = (*s)[l];
	t = ft_calloc(ft_strlen(*s) - getnl(*s), sizeof(char));
	l = getnl(*s) + 1;
	while ((*s)[l] != '\0')
		t[i++] = (*s)[l++];
	t[i] = '\0';
	free(*s);
	*s = NULL;
	*s = t;
	return (u);
}

void	append(char **s, char **b)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*b))
		return ;
	t = ft_calloc(ft_strlen(*s) + ft_strlen(*b) + 1, sizeof(char));
	if (!t)
		return ;
	while ((*s)[i] != '\0')
		t[j++] = (*s)[i++];
	i = 0;
	while ((*b)[i] != '\0')
		t[j++] = (*b)[i++];
	free(*s);
	*s = NULL;
	free(*b);
	*b = NULL;
	*s = t;
}
