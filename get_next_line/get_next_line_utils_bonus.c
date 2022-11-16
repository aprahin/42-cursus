/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:44:48 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/16 11:45:06 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
	return ;
}

void	*ft_calloc(int count, int size)
{
	void			*array;
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
	ft_bzero(array, len);
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

char	*trimtonl(char **s, char *b)
{
	char	*t;
	char	*u;
	int		l;
	int		i;

	if (!s)
		return (0);
	i = 0;
	l = getnl(*s) + 1;
	u = ft_calloc((l + 1), sizeof(char));
	if (!u)
		return (0);
	while (l--)
		u[l] = (*s)[l];
	l = getnl(*s) + 1;
	t = ft_calloc((ft_strlen(*s) - (l - 1)), sizeof(char));
	while ((*s)[l] != '\0')
		t[i++] = (*s)[l++];
	if (b)
		free(b);
	free(*s);
	*s = t;
	return (u);
}
