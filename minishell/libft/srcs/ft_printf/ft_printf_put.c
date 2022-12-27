/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprotsen <eprotsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:42:03 by eprotsen          #+#    #+#             */
/*   Updated: 2022/11/28 05:50:55 by eprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

//wrapers around ft_put functions that affect printf struct charsprinted
void	printf_putchar(t_count *print, char c, int fd)
{
	ft_putchar_fd(c, fd);
	print->chars_printed = print->chars_printed + 1;
}

void	printf_putstr(t_count *print, char *str, int fd)
{
	ft_putstr_fd(str, fd);
	print->chars_printed = print->chars_printed + ft_strlen(str);
}

void	printf_putnbr(t_count *print, int n, int fd)
{
	char	*str;

	str = ft_itoa(n);
	printf_putstr(print, str, fd);
	free(str);
}
