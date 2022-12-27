/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprotsen <eprotsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:43:45 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/27 09:20:25 by eprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "halloc.h"

void	*hmalloc(int size)
{
	t_heap			*new;
	t_heap			*ptr;

	new = malloc(sizeof(t_heap) + size);
	if (new == NULL)
		return (NULL);
	new->data = ptr_move(new, sizeof(t_heap));
	new->next = NULL;
	ptr = get_first_heap();
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (new->data);
}
