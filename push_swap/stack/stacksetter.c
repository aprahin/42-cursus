/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksetter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:34:10 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/27 20:14:10 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_setn(t_stack *self, int value, int pos)
{
	if (!self || pos < 0 || pos >= stack_getsize(self))
		return ;
	self->nbs[pos] = value;
}

void	stack_setnbs(t_stack *self, int *value)
{
	if (!self)
		return ;
	self->nbs = value;
}

void	stack_setsize(t_stack *self, int value)
{
	if (!self)
		return ;
	self->size = value;
}
