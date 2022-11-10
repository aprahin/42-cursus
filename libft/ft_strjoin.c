/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:52:33 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/31 16:04:23 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (s1[i++] != '\0')
		j++;
	i = 0;
	while (s2[i++] != '\0')
		j++;
	s = malloc((j + 1) * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
