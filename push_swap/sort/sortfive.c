/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:37:11 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/30 00:24:50 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

char	*sortfive(t_stack *a, t_stack *b)
{
	char	*moves;

	if (stack_getn(a, 0) == 1)
		moves = ft_strdup("");
	else if (stack_getn(a, 1) == 1)
		moves = ft_strdup("ra\n");
	else if (stack_getn(a, 2) == 1)
		moves = ft_strdup("ra\nra\n");
	else if (stack_getn(a, 3) == 1)
		moves = ft_strdup("rra\nrra\n");
	else
		moves = ft_strdup("rra\n");
	stack_play(a, b, moves);
	if (stack_sorted(a))
		return (moves);
	moves = ft_strjoinf(moves, "pb\n", 1, 0);
	stack_push(b, a);
	moves = ft_strjoinf(moves, sortfour(a), 1, 1);
	moves = ft_strjoinf(moves, "pa\n", 1, 0);
	return (moves);
}
