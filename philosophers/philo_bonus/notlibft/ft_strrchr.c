/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:25:09 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/09 15:01:28 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "notlibft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		found;
	char	*pos;

	i = 0;
	found = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c % 256)
		{
			pos = (char *)(s + i);
			found = 1;
		}
		++i;
	}
	if (c % 256 == '\0')
		return ((char *)(s + i));
	if (found)
		return (pos);
	return (0);
}
