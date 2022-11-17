/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:11:27 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/10 20:11:27 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*endread(char **s, char *b, int r)
{
	if (r == 0)
	{
		if (*s && (*s)[0] != '\0')
		{
			free(b);
			b = ft_calloc((ft_strlen(*s) + 1), sizeof(char));
			if (!b)
				return (0);
			while ((*s)[r++] != '\0')
				b[r - 1] = (*s)[r - 1];
			free(*s);
			*s = NULL;
			return (b);
		}
		free(*s);
		*s = NULL;
		free(b);
		return (0);
	}
	free(b);
	free(*s);
	*s = NULL;
	return (0);
}

int	makestr(char **s, int fd)
{
	int	r;

	r = 0;
	*s = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!(*s))
		return (0);
	r = read(fd, *s, BUFFER_SIZE);
	if (r <= 0)
	{
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*b;
	static char	*s;
	int			r;

	if (!s && !makestr(&s, fd))
		return (0);
	while (getnl(s) < 0)
	{	
		b = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!b)
			return (0);
		r = read(fd, b, BUFFER_SIZE);
		if (r <= 0)
			return (endread(&s, b, r));
		append(&s, &b);
	}
	return (trimtonl(&s));
}
