/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprotsen <eprotsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:16:10 by eprotsen          #+#    #+#             */
/*   Updated: 2022/11/28 05:50:55 by eprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_str;
	const char	*src_str;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	dest_str = (char *) dest;
	src_str = (const char *) src;
	i = 0;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dest);
}
