/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:39:03 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 00:28:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = hmalloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = s[i];
		++i;
	}
	newstr[i] = '\0';
	return (newstr);
}
