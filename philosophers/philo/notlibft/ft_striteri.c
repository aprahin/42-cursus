/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:50:24 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/09 15:01:28 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "notlibft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &(s[i]));
		++i;
	}
	return ;
}
