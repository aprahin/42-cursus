/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:16:49 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/08 16:06:37 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_in(const char c, const char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (i + 1);
		++i;
	}
	return (0);
}
