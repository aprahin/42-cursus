/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:53:39 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 01:07:09 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	initstacks(t_stack **a, t_stack **b, char **argv, int argc)
{
	*a = stack_make(argv, argc);
	*b = stack_create(0, 0);
}

static int	checkargerr(int i)
{
	if (i == 0)
		ft_putstr_fd("Error\n", 2);
	return (i);
}

int	main(int argc, char **argv)
{
	int		l;
	char	*moves[69420];
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!checkargerr(checkargs(argc, argv)))
		return (0);
	l = readmoves(moves);
	if (l < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	initstacks(&a, &b, argv, argc);
	if (checkmoves(a, b, moves, l))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_destroy(a);
	stack_destroy(b);
	while (l--)
		free(moves[l]);
	return (0);
}
