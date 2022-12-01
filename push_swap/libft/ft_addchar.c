/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:12:25 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/27 20:05:06 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_addchar(char **str, char c, int start)
{
	int	i;

	i = start;
	while ((*str)[i] != '\0')
		++i;
	(*str)[i] = c;
}
