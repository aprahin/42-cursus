/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:40:27 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 00:28:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static size_t	words_amount(char const *s, char c)
{
	size_t	words_am;
	size_t	isword;

	words_am = 0;
	isword = 0;
	while (*s)
	{
		if (*s != c && !isword)
		{
			isword = 1;
			words_am++;
		}
		else if (*s == c)
			isword = 0;
		s++;
	}
	return (words_am);
}

static char	**init_split(char const *s, char c, char **res, size_t s_len)
{
	size_t	i;
	size_t	words_am;
	size_t	word_len;

	i = 0;
	words_am = 0;
	word_len = 0;
	while (i < s_len + 1 && s_len > 0)
	{
		if (s[i] == c || !s[i])
		{
			if (word_len > 0)
			{
				res[words_am] = hmalloc((word_len + 1) * sizeof(char));
				if (res[words_am])
					ft_strlcpy(res[words_am], &s[i - word_len], word_len + 1);
				word_len = 0;
				words_am++;
			}
		}
		else
			word_len++;
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_am;
	size_t	s_len;
	char	**res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	words_am = words_amount(s, c);
	res = hmalloc(sizeof(char *) * (words_am + 1));
	if (!res)
		return (NULL);
	res = init_split(s, c, res, s_len);
	res[words_am] = NULL;
	return (res);
}
