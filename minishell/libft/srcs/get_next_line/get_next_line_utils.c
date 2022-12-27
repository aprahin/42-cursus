/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:13:51 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 00:29:35 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

size_t	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	gnl_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (gnl_strlen(src));
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	if (!s1)
	{
		s1 = (char *)hmalloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len_s1 = (gnl_strlen((char *)s1));
	len_s2 = (gnl_strlen((char *)s2));
	res = (char *)hmalloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	gnl_strlcpy(res, s1, len_s1 + 1);
	gnl_strlcpy(&res[len_s1], s2, len_s2 + 1);
	hfree(s1);
	return (res);
}
