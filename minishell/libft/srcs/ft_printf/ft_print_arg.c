/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprotsen <eprotsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:41:47 by eprotsen          #+#    #+#             */
/*   Updated: 2022/11/28 05:50:55 by eprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

void	print_arg(t_count *print, va_list args)
{
	if (print->format_char == 'u')
	{
		print->type_u = va_arg(args, unsigned int);
		print_u(print, print->type_u, 1);
	}
	else if (print->format_char == 'x' || print->format_char == 'X')
	{
		print->type_x_x = va_arg(args, unsigned int);
		print_x(print, print->type_x_x, 1);
	}
	else if (print->format_char == 'd' || print->format_char == 'i')
	{
		print->type_d_i = va_arg(args, int);
		printf_putnbr(print, print->type_d_i, 1);
	}
	else
		print_arg2(print, args);
}

//printf takes an int as arg, but performs conversion to a char value
void	print_arg2(t_count *print, va_list args)
{
	if (print->format_char == 'c')
	{
		print->type_c = va_arg(args, int);
		printf_putchar(print, print->type_c, 1);
	}
	else if (print->format_char == 's')
	{
		print->type_s = va_arg(args, char *);
		if (print->format_char == 's' && !print->type_s)
			print->type_s = "(null)";
		printf_putstr(print, print->type_s, 1);
	}
	else if (print->format_char == 'p')
	{
		print->type_p = va_arg(args, unsigned long);
		printf_putstr(print, "0x", 1);
		print_p(print, print->type_p, 1);
	}
	else if (print->format_char == '%')
		printf_putchar(print, '%', 1);
}
