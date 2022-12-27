/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:34:36 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/25 14:48:32 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "halloc.h"
/*void	hfree(void *data)
{
	t_heap	*ptr;
	t_heap	*prev;

	ptr = get_first_heap();
	if (ptr == NULL)
		return ;
	prev = NULL;
	while (ptr->data != data)
	{
		if (ptr->next == NULL)
			return ;
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr->next != NULL && prev != NULL)
		prev->next = ptr->next;
	else if (prev != NULL)
		prev->next = NULL;
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}*/

void	hfree(void *data)
{
	t_heap	*ptr;
	t_heap	*tmp;

	if (data == NULL)
		return ;
	ptr = ptr_move(data, -((int) sizeof(t_heap)));
	tmp = get_first_heap();
	while (tmp->next && tmp->next != ptr)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return ;
	tmp->next = ptr->next;
	free(ptr);
	ptr = NULL;
}
