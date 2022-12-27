/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hobliterate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:41:41 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/25 01:12:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "halloc.h"

void	hobliterate(void)
{
	t_heap	*ptr;
	t_heap	*tmp;

	ptr = get_first_heap();
	if (!ptr)
		return ;
	while (ptr->next)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(ptr);
	ptr = NULL;
}
