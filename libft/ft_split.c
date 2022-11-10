/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:49:06 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/04 17:49:06 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_str(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] == '\0')
			break ;
		++n;
		while (s[i] != c && s[i] != '\0')
			++i;
	}
	return (n);
}

static int	freeifsus(char ***t, size_t m)
{
	if (!((*t)[m]))
	{
		while (m > 0)
		{
			free((*t)[m - 1]);
			m--;
		}
		return (1);
	}
	return (0);
}

static int	mallocall(char ***t, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	m;

	i = 0;
	j = 0;
	m = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
		{
			++i;
			++j;
		}
		(*t)[m] = malloc(sizeof(char) * (j + 1));
		if (freeifsus(t, m))
			return (0);
		m++;
		j = 0;
	}
	return (1);
}

static void	writeinto(char ***t, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	m;

	i = 0;
	j = 0;
	m = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			(*t)[m][j++] = s[i++];
		(*t)[m][j] = '\0';
		m++;
		j = 0;
	}
	(*t)[m] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	size_t	n;

	n = count_str(s, c);
	t = malloc(sizeof(char *) * (n + 1));
	if (!t)
		return (0);
	if (!mallocall(&t, s, c))
		return (0);
	writeinto(&t, s, c);
	return (t);
}
