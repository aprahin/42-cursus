/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:43:27 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/01 11:51:05 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	if (src == dst)
		return (dst);
	p = dst;
	q = (void *) src;
	while (n > 0)
	{
		*p = *q;
		p++;
		q++;
		n--;
	}
	return (dst);
}
