/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:08:06 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:48:08 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

char	*optimoves(char *moves, t_stack *a, t_stack *b)
{
	char	*opti;

	opti = optips(moves);
	if (a)
		opti = optirot(opti, "ra", stack_getsize(a));
	if (b)
		opti = optirot(opti, "rb", stack_getsize(b));
	return (opti);
}

int	getmax(t_stack *a)
{
	int	l;
	int	n;

	l = stack_getsize(a);
	n = stack_getn(a, l - 1);
	while (l--)
	{
		if (stack_getn(a, l) > n)
			n = stack_getn(a, l);
	}
	return (n);
}

int	getmin(t_stack *a)
{
	int	l;
	int	n;

	l = stack_getsize(a);
	n = stack_getn(a, l - 1);
	while (l--)
	{
		if (stack_getn(a, l) < n)
			n = stack_getn(a, l);
	}
	return (n);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
