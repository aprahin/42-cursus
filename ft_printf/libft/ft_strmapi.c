/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:41:04 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/31 15:58:37 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		l;
	char	*t;

	l = 0;
	while (s[l] != '\0')
		++l;
	t = malloc(sizeof(char) * (l + 1));
	if (!t)
		return (0);
	i = 0;
	while (i < l)
	{
		t[i] = (*f)(i, s[i]);
		++i;
	}
	t[i] = '\0';
	return (t);
}
