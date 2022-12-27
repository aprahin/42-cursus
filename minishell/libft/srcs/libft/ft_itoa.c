/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:40:35 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 00:28:41 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static	int	n_length(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		n_int;
	int		n_len;
	char	*res;

	n_int = (long int)n;
	n_len = n_length(n_int);
	res = hmalloc((n_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	res[n_len] = '\0';
	while (n_int)
	{
		res[--n_len] = (n_int % 10) * ((2 * (n > 0)) - 1) + '0';
		n_int /= 10;
	}
	if (n < 0)
		res[--n_len] = '-';
	return (res);
}
