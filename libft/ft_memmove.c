/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:06:23 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/01 12:05:42 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;

	if (dst == src)
		return (dst);
	i = 0;
	p = dst;
	q = (void *) src;
	if (q < p)
	{
		while (len-- > 0)
			p[len] = q[len];
	}
	else
	{
		while (i < len)
		{
			p[i] = q[i];
			++i;
		}
	}
	return (dst);
}
