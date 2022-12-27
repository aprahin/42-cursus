/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:07:56 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/12 16:42:55 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HALLOC_H
# define HALLOC_H

/*
 *	malloc
 *	free
 */
# include <stdlib.h>

typedef struct s_heap
{
	void			*data;
	struct s_heap	*next;
}	t_heap;
/*
 *	struct:			t_heap
 *
 *	desc:			stores a pointer to allocated memory
 *
 *	data:			allocated memory with malloc
 *	next:			next t_heap, points to NULL if last
 */

void				*hmalloc(int size);
/*
 *	func:			hmalloc
 *
 *	desc:			allocates memory with malloc, adds it to t_heap
 *	
 *	size:			exact size to be malloc
 *	
 *	return:			pointer to allocated memory
 */

void				*hcalloc(int count, int size);
/*
 *	func:			hcalloc
 *
 *	desc:			allocates memory filled with zeros, adds it to t_heap
 *
 *	count:			amount of objects to allocate memory for
 *	size:			size of each objects in bytes
 *
 *	return:			pointer to allocated memory
 */

void				hfree(void	*data);
/*
 *	func:			hfree
 *
 *	desc:			frees memory, relinks t_heap
 *
 *	data:			hallocated data
 */

void				hobliterate(void);
/*
 *	func:			hobliterate
 *
 *	desc:			frees all memory in t_heap
 *
 * 	notes:			can't be called twice or DEATH
 */

t_heap				*get_first_heap(void);
/*
 *	func:			get_first_heap
 *
 *	desc:			returns start of t_heap and/or sets it
 *
 *	return:			start of t_heap linked list
 *
 *	notes:			should be replaced by a global variable
 */

void				*ptr_move(void *ptr, int dist);
/*
 *	func:			ptr_move
 *
 *	desc:			return pointer with an offset
 *
 *	ptr:			pointer to move
 *	dist:			distance to move pointer in bytes
 *
 *	return:			original pointer moved by dist
 */

#endif