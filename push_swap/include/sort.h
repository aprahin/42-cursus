/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:58:00 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/01 01:10:59 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "stack.h"
# include "libft.h"

typedef struct s_rot{
	int	rget;
	int	rrget;
	int	rset;
	int	rrset;
	int	rr;
	int	rrr;
	int	total;
}	t_rot;

char	*sortbogo(t_stack *a, t_stack *b);
char	*sortthree(t_stack *a);
char	*sortfour(t_stack *a);
char	*sortfive(t_stack *a, t_stack *b);
char	*sortbubble(t_stack *a);
char	*sortselect(t_stack *a, t_stack *b);
char	*sortinsert(t_stack *a, t_stack *b);
char	*sortbessert(t_stack *a, t_stack *b);

/* sortutils.c */

char	*optimoves(char *moves, t_stack *a, t_stack *b);
int		getmax(t_stack *a);
int		getmin(t_stack *a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

/* sortbessertutils.c */

void	setrottop(t_stack *b, t_rot *rots);
void	setrotmid(t_stack *b, t_rot *rots, int n);
void	setbest(t_rot *rots);

/* optirot.c */

char	*optirot(char *moves, char *rot, int size);

/* optips.c */

char	*optips(char *moves);

#endif