/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackgetter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:53:37 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/27 20:13:43 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_getn(t_stack *self, int pos)
{
	if (!self || pos < 0 || pos >= stack_getsize(self))
		return (0);
	return (self->nbs[pos]);
}

int	*stack_getnbs(t_stack *self)
{
	if (!self)
		return (0);
	return (self->nbs);
}

int	stack_getsize(t_stack *self)
{
	if (!self)
		return (0);
	return (self->size);
}
