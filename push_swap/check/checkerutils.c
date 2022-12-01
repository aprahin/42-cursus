/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:13:41 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 01:10:30 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	isvalidmove(char *move)
{
	int		n;
	char	*set[11];

	n = 11;
	set[0] = "sa";
	set[1] = "sb";
	set[2] = "ss";
	set[3] = "pa";
	set[4] = "pb";
	set[5] = "ra";
	set[6] = "rb";
	set[7] = "rr";
	set[8] = "rra";
	set[9] = "rrb";
	set[10] = "rrr";
	while (n--)
	{
		if (ft_strncmp(move, set[n], 5) == 0)
			return (1);
	}
	return (0);
}

static void	checkpush(t_stack *a, t_stack *b, char *move)
{
	if (!ft_strncmp(move, "pa", 2))
		stack_push(a, b);
	if (!ft_strncmp(move, "pb", 2))
		stack_push(b, a);
}

int	checkmoves(t_stack *a, t_stack *b, char **moves, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!ft_strncmp(moves[i], "sa", 2) || !ft_strncmp(moves[i], "ss", 2))
			stack_swap(a);
		if (!ft_strncmp(moves[i], "sb", 2) || !ft_strncmp(moves[i], "ss", 2))
			stack_swap(b);
		checkpush(a, b, moves[i]);
		if (!ft_strncmp(moves[i], "ra", 2) || !ft_strncmp(moves[i], "rr", 3))
			stack_rot(a);
		if (!ft_strncmp(moves[i], "rb", 2) || !ft_strncmp(moves[i], "rr", 3))
			stack_rot(b);
		if (!ft_strncmp(moves[i], "rra", 3) || !ft_strncmp(moves[i], "rrr", 3))
			stack_rev(a);
		if (!ft_strncmp(moves[i], "rrb", 3) || !ft_strncmp(moves[i], "rrr", 3))
			stack_rev(b);
		++i;
	}
	if (stack_getsize(b) > 0 || !stack_sorted(a))
		return (0);
	return (1);
}

int	readmoves(char **moves)
{
	int		i;
	char	*read;

	i = 0;
	read = get_next_line(0);
	while (read)
	{
		if (!isvalidmove(read))
		{
			free(read);
			while (i--)
				free(moves[i]);
			return (-1);
		}
		moves[i++] = read;
		read = get_next_line(0);
	}
	return (i);
}
