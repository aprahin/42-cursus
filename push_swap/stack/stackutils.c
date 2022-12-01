/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:05:42 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:12:25 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_print(t_stack *self)
{
	int	i;
	int	l;

	if (!self)
		return ;
	l = stack_getsize(self);
	if (l == 0)
		ft_printf("(empty)");
	i = 0;
	while (i < l)
	{
		ft_printf("%i", stack_getn(self, i));
		++i;
		if (i < l)
			ft_printf(" ");
	}
	ft_printf("\n");
}

int	stack_sorted(t_stack *self)
{
	int	i;
	int	n;
	int	l;

	if (!self)
		return (0);
	i = 1;
	n = stack_getn(self, 0);
	l = stack_getsize(self);
	while (i < l)
	{
		if (n >= stack_getn(self, i))
			return (0);
		n = stack_getn(self, i);
		++i;
	}
	return (1);
}

t_stack	*stack_make(char **argv, int argc)
{
	int		i;
	int		*nbs;
	t_stack	*stack;

	nbs = (int *) malloc(sizeof(int) * (argc - 1));
	if (!nbs)
		return (0);
	i = 0;
	while (++i < argc)
		nbs[i - 1] = ft_atoi(argv[i]);
	stack = stack_create(nbs, argc - 1);
	return (stack);
}

static char	**initlist(char *moves, int *i)
{
	*i = 0;
	return (ft_split(moves, '\n'));
}

void	stack_play(t_stack *a, t_stack *b, char *moves)
{
	int		i;
	char	**mlist;

	mlist = initlist(moves, &i);
	while (mlist[i] != 0)
	{
		if (!ft_strncmp(mlist[i], "sa", 2) || !ft_strncmp(mlist[i], "ss", 2))
			stack_swap(a);
		if (!ft_strncmp(mlist[i], "sb", 2) || !ft_strncmp(mlist[i], "ss", 2))
			stack_swap(b);
		if (!ft_strncmp(mlist[i], "pa", 2))
			stack_push(a, b);
		if (!ft_strncmp(mlist[i], "pb", 2))
			stack_push(b, a);
		if (!ft_strncmp(mlist[i], "ra", 2) || !ft_strncmp(mlist[i], "rr", 3))
			stack_rot(a);
		if (!ft_strncmp(mlist[i], "rb", 2) || !ft_strncmp(mlist[i], "rr", 3))
			stack_rot(b);
		if (!ft_strncmp(mlist[i], "rra", 3) || !ft_strncmp(mlist[i], "rrr", 3))
			stack_rev(a);
		if (!ft_strncmp(mlist[i], "rrb", 3) || !ft_strncmp(mlist[i], "rrr", 3))
			stack_rev(b);
		free(mlist[i++]);
	}
	free(mlist);
}
