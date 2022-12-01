/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbessert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:41:44 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 01:00:16 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	writemorerots(t_stack *a, t_stack *b, char **moves, t_rot rots)
{
	while (rots.rr--)
	{
		*moves = ft_strjoinf(*moves, "rr\n", 1, 0);
		stack_rot(a);
		stack_rot(b);
	}
	while (rots.rrr--)
	{
		*moves = ft_strjoinf(*moves, "rrr\n", 1, 0);
		stack_rev(a);
		stack_rev(b);
	}
	*moves = ft_strjoinf(*moves, "pb\n", 1, 0);
	stack_push(b, a);
}

static void	writerots(t_stack *a, t_stack *b, char **moves, t_rot rots)
{
	while (rots.rget--)
	{
		*moves = ft_strjoinf(*moves, "ra\n", 1, 0);
		stack_rot(a);
	}
	while (rots.rrget--)
	{
		*moves = ft_strjoinf(*moves, "rra\n", 1, 0);
		stack_rev(a);
	}
	while (rots.rset--)
	{
		*moves = ft_strjoinf(*moves, "rb\n", 1, 0);
		stack_rot(b);
	}
	while (rots.rrset--)
	{
		*moves = ft_strjoinf(*moves, "rrb\n", 1, 0);
		stack_rev(b);
	}
	writemorerots(a, b, moves, rots);
}

static t_rot	bestrot(t_stack *a, t_stack *b)
{
	int		i;
	t_rot	rots;
	t_rot	best;

	i = 0;
	best.total = -1;
	while (i < stack_getsize(a))
	{
		rots.rget = i;
		rots.rrget = (stack_getsize(a) - i) % stack_getsize(a);
		if (stack_getn(a, i) < getmin(b) || stack_getn(a, i) > getmax(b))
			setrottop(b, &rots);
		else
			setrotmid(b, &rots, stack_getn(a, i));
		rots.rr = 0;
		rots.rrr = 0;
		setbest(&rots);
		if (best.total < 0 || rots.total < best.total)
			best = rots;
		++i;
	}
	return (best);
}

static void	pushback(t_stack *a, t_stack *b, char **moves)
{
	while (stack_getn(b, stack_getsize(b) - 1) != 1)
	{
		*moves = ft_strjoinf(*moves, "rb\n", 1, 0);
		stack_rot(b);
	}
	while (stack_getsize(b) > 0)
	{
		*moves = ft_strjoinf(*moves, "pa\n", 1, 0);
		stack_push(a, b);
	}
}

char	*sortbessert(t_stack *a, t_stack *b)
{
	int		n;
	char	*moves;
	t_rot	rots;

	moves = ft_strdup("pb\npb\n");
	stack_push(b, a);
	stack_push(b, a);
	if (stack_sorted(b))
	{
		moves = ft_strjoinf(moves, "sb\n", 1, 0);
		stack_swap(b);
	}
	n = stack_getsize(a);
	while (n-- > 0)
	{
		rots = bestrot(a, b);
		writerots(a, b, &moves, rots);
	}
	pushback(a, b, &moves);
	return (optimoves(moves, a, b));
}
