/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:37:39 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 16:41:08 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *) big);
	while (len && big[i] && i + little_len <= len)
	{
		if (!ft_strncmp(&big[i], little, little_len + 1))
			return ((char *) &big[i]);
		i++;
	}
	return (0);
}
