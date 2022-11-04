/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:44:58 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/25 14:59:00 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
	{
		return ((char *)(haystack));
	}
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && i < len)
	{
		while ((haystack[i] == needle[j] || needle[j] == '\0') && i <= len)
		{
			if (needle[j] == '\0')
			{
				return ((char *)(haystack + i - j));
			}
			++i;
			++j;
		}
		i -= j;
		j = 0;
		++i;
	}
	return (0);
}
