/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:45:57 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:01:23 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*sort(t_stack *a, t_stack *b, int n)
{
	char	*moves;

	if (n == 2)
		moves = ft_strdup("sa\n");
	else if (n == 3)
		moves = sortthree(a);
	else if (n == 4)
		moves = sortfour(a);
	else if (n == 5)
		moves = sortfive(a, b);
	else
		moves = sortbessert(a, b);
	return (moves);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*moves;

	if (argc == 1)
		return (0);
	if (!checkargs(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	a = stack_make(argv, argc);
	stack_index(a);
	b = stack_create(0, 0);
	if (!stack_sorted(a))
	{
		moves = sort(a, b, argc - 1);
		ft_printf("%s", moves);
		free(moves);
	}
	stack_destroy(a);
	stack_destroy(b);
	return (0);
}
