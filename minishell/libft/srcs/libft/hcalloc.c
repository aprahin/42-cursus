/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hcalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:13:58 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/13 00:09:58 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "halloc.h"

void	*hcalloc(int count, int size)
{
	int		i;
	char	*data;

	data = hmalloc(count * size);
	i = -1;
	while (++i < count * size)
		*(data + i) = '\0';
	return (data);
}
