/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:36:13 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 00:51:30 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "stack.h"
# include "libft.h"
# include "utils.h"

/* checkerutils.c */

int	isvalidmove(char *move);
int	checkmoves(t_stack *a, t_stack *b, char **moves, int count);
int	readmoves(char **moves);

#endif