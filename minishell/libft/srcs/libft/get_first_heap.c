/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_heap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:28:01 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/13 00:10:00 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "halloc.h"

t_heap	*get_first_heap(void)
{
	static t_heap	*start = NULL;

	if (start == NULL)
	{
		start = malloc(sizeof(t_heap));
		start->data = NULL;
		start->next = NULL;
	}
	return (start);
}
