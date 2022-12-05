/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:47:01 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/25 13:47:55 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	i = 0;
	srclen = 0;
	destlen = 0;
	while (dest[destlen] != '\0')
		++destlen;
	while (src[srclen] != '\0')
	{
		++srclen;
	}
	if (size <= destlen)
	{
		return (srclen + size);
	}
	while (src[i] != '\0' && i < size - destlen - 1)
	{
		dest[destlen + i] = src[i];
		++i;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
