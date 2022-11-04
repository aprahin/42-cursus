/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:09:53 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/01 11:44:51 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	writeinto(char const *s, char **sub, unsigned int start, size_t i)
{
	unsigned int	n;

	n = 0;
	while (n < (unsigned int) i)
	{
		(*sub)[n] = s[start + n];
		++n;
	}
	(*sub)[n] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	n;
	size_t	i;

	n = 0;
	while (s[n] != '\0')
		++n;
	if (start >= n || len == 0)
	{
		sub = malloc(sizeof(char) * 1);
		sub[0] = '\0';
		return (sub);
	}
	i = 0;
	while ((start + i) < n && i < len)
		++i;
	sub = malloc(sizeof(char) * (i + 1));
	if (!sub)
		return (0);
	writeinto(s, &sub, start, i);
	return (sub);
}
