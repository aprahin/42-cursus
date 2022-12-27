/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:40:02 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 00:28:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	s1len;
	unsigned int	s2len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = hmalloc(s1len + s2len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s1len + s2len)
	{
		if (i < s1len)
			res[i] = s1[i];
		else
			res[i] = s2[i - s1len];
		i++;
	}
	res[i] = '\0';
	return (res);
}
