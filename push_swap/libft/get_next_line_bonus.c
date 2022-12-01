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

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	s = malloc((j + 1) * sizeof(char));
	if (!s)
		return (0);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i] = '\0';
	free(s1);
	return (s);
}

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

int	makefd(char **s, int fd)
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
	static char	*t[4096];
	int			r;

	if (fd < 0)
		return (0);
	if (!(t[fd]) && !makefd(&(t[fd]), fd))
		return (0);
	b = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!b)
		return (0);
	while (getnl(t[fd]) < 0)
	{
		ft_bzero(b, BUFFER_SIZE + 1);
		r = read(fd, b, BUFFER_SIZE);
		if (r <= 0)
			return (endread(&(t[fd]), b, r));
		t[fd] = ft_strjoin(t[fd], b);
	}
	return (trimtonl(&(t[fd]), b));
}
