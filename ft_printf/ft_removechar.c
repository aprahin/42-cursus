/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:22:49 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/10 18:22:49 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_removechar(char	**str, const char *charset)
{
	int	i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if (ft_in((*str)[i], charset))
			(*str)[i] = '_';
		++i;
	}
}
