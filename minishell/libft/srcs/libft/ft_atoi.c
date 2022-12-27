/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprotsen <eprotsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:40:47 by eprotsen          #+#    #+#             */
/*   Updated: 2022/11/28 05:50:55 by eprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_atoi(const char *nptr)
{
	int	nint;
	int	nold;
	int	sign;

	sign = 1;
	nint = 0;
	nold = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		if (nint == 214748364 && *nptr == '8' && sign == -1)
			return (-2147483648);
		nold = nint;
		nint = nint * 10 + (*nptr - '0');
		if ((nold < 0 && nint > 0) || (nold > 0 && nint < 0))
			return ((sign == 1) * -1);
		nptr++;
	}
	return (sign * nint);
}
