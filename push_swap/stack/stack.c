/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:58:41 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/29 23:03:37 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_create(int *nbs, int size)
{
	t_stack	*newstack;

	newstack = (t_stack *) malloc(sizeof(t_stack));
	if (!newstack)
		return (0);
	stack_setnbs(newstack, nbs);
	stack_setsize(newstack, size);
	return (newstack);
}

void	stack_init(t_stack *self, int *nbs, int size)
{
	if (!self)
		return ;
	self->nbs = nbs;
	self->size = size;
}

void	stack_reset(t_stack *self)
{
	if (!self)
		return ;
	if (stack_getnbs(self))
		free(stack_getnbs(self));
	stack_setnbs(self, 0);
	stack_setsize(self, 0);
}

void	stack_destroy(t_stack *self)
{
	if (!self)
		return ;
	stack_reset(self);
	free(self);
}

t_stack	*stack_dup(t_stack *self)
{
	t_stack	*newstack;
	int		*newnbs;

	if (!self)
		return (0);
	newstack = (t_stack *) malloc(sizeof(t_stack));
	if (!newstack)
		return (0);
	stack_setsize(newstack, stack_getsize(self));
	newnbs = (int *) malloc(stack_getsize(self) * sizeof(int));
	ft_memmove(newnbs, stack_getnbs(self), stack_getsize(self) * sizeof(int));
	stack_setnbs(newstack, newnbs);
	return (newstack);
}
