/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:07:19 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/05 11:04:37 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	isin(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

static size_t	getlen(char const *s1, char const *set)
{
	int		i;
	size_t	n;

	i = 0;
	n = 0;
	while (isin(s1[i], set))
		++i;
	if (s1[i] == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		i++;
		n++;
	}
	i--;
	while (isin(s1[i], set))
	{
		i--;
		n--;
	}
	return (n);
}

static size_t	stopid(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (isin(s1[i], set))
	{
		++i;
	}
	if (s1[i] == '\0')
		return (0);
	while (s1[i] != '\0')
		i++;
	i--;
	while (isin(s1[i], set))
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	i;
	int		j;
	size_t	end;

	if (s1[0] == '\0')
	{
		s = malloc(1);
		s[0] = '\0';
		return (s);
	}
	s = malloc((getlen(s1, set) + 1) * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	j = 0;
	end = stopid(s1, set);
	while (isin(s1[i], set))
		++i;
	while (i <= end)
	{
		s[j++] = s1[i++];
	}
	s[j] = '\0';
	return (s);
}
