/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:03:17 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/31 16:11:09 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*s;

	i = 0;
	while (src[i] != '\0')
		++i;
	s = malloc(i + 1);
	if (!s)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		s[i] = src[i];
		++i;
	}
	s[i] = '\0';
	return (s);
}
