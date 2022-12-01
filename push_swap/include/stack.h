/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:47:54 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:11:01 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"

typedef struct s_stack{
	int	*nbs;
	int	size;
}	t_stack;

/* stack.c */

t_stack	*stack_create(int *nbs, int size);
void	stack_init(t_stack *self, int *nbs, int size);
void	stack_reset(t_stack *self);
void	stack_destroy(t_stack *self);
t_stack	*stack_dup(t_stack *self);

/* stacksetter.c */

void	stack_setn(t_stack *self, int value, int pos);
void	stack_setnbs(t_stack *self, int *value);
void	stack_setsize(t_stack *self, int value);

/* stackgetter.c */

int		stack_getn(t_stack *self, int pos);
int		*stack_getnbs(t_stack *self);
int		stack_getsize(t_stack *self);

/* stackmove.c */

void	stack_swap(t_stack *self);
void	stack_push(t_stack *dst, t_stack *src);
void	stack_rot(t_stack *self);
void	stack_rev(t_stack *self);

/* stackutils.c */

void	stack_print(t_stack *self);
int		stack_sorted(t_stack *self);
t_stack	*stack_make(char **argv, int argc);
void	stack_play(t_stack *a, t_stack *b, char *moves);

/* stackutils2.c */

char	*stack_getmark(t_stack *self);
void	stack_index(t_stack *self);

#endif