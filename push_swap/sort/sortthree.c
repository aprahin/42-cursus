/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:33:16 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:02:12 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

/*char	*sortthree(t_stack *a, t_stack *b)
{
	int	x;
	int	y;
	int	z;

	x = stack_getn(a, 0);
	y = stack_getn(a, 1);
	z = stack_getn(a, 2);
	if (x < y && y < z)
		return (ft_strdup(""));
	if (x < y && y > z && x < z)
		return (ft_strdup("rra\nsa"));
	if (x > y && y < z && x < z)
		return (ft_strdup("sa"));
	if (x < y && y > z && x > z)
		return (ft_strdup("rra"));
	if (x > y && y < z && x > z)
		return (ft_strdup("ra"));
	return (ft_strdup("ra\nsa"));
}*/

char	*sortthree(t_stack *a)
{
	char	*mark;
	char	*moves;

	mark = stack_getmark(a);
	if (!ft_strncmp(mark, "1 2 3", 5))
		moves = ft_strdup("");
	else if (!ft_strncmp(mark, "1 3 2", 5))
		moves = ft_strdup("rra\nsa\n");
	else if (!ft_strncmp(mark, "2 1 3", 5))
		moves = ft_strdup("sa\n");
	else if (!ft_strncmp(mark, "2 3 1", 5))
		moves = ft_strdup("rra\n");
	else if (!ft_strncmp(mark, "3 1 2", 5))
		moves = ft_strdup("ra\n");
	else
		moves = ft_strdup("ra\nsa\n");
	free(mark);
	return (moves);
}
