/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:46:37 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/27 22:47:15 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap(t_stack *self)
{
	int	tmp;

	if (stack_getsize(self) < 2)
		return ;
	tmp = stack_getn(self, 0);
	stack_setn(self, stack_getn(self, 1), 0);
	stack_setn(self, tmp, 1);
}

void	stack_push(t_stack *dst, t_stack *src)
{
	int	l;
	int	*nbs;

	if (!dst || !src || stack_getsize(src) <= 0)
		return ;
	l = stack_getsize(dst);
	nbs = (int *) malloc(sizeof(int) * (l + 1));
	nbs[0] = stack_getn(src, 0);
	ft_memcpy(nbs + 1, stack_getnbs(dst), sizeof(int) * l);
	stack_reset(dst);
	stack_init(dst, nbs, l + 1);
	l = stack_getsize(src);
	nbs = (int *) malloc(sizeof(int) * (l - 1));
	ft_memcpy(nbs, stack_getnbs(src) + 1, sizeof(int) * (l - 1));
	stack_reset(src);
	stack_init(src, nbs, l - 1);
}

void	stack_rot(t_stack *self)
{
	int	i;
	int	tmp;
	int	l;

	l = stack_getsize(self);
	if (l < 2)
		return ;
	tmp = stack_getn(self, 0);
	i = 1;
	while (i < l)
	{
		stack_setn(self, stack_getn(self, i), i - 1);
		++i;
	}
	stack_setn(self, tmp, i - 1);
}

void	stack_rev(t_stack *self)
{
	int	i;
	int	tmp;
	int	l;

	l = stack_getsize(self);
	if (l < 2)
		return ;
	tmp = stack_getn(self, l - 1);
	i = l - 2;
	while (i >= 0)
	{
		stack_setn(self, stack_getn(self, i), i + 1);
		--i;
	}
	stack_setn(self, tmp, 0);
}
