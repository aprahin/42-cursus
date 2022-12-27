/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <aprahin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:41:30 by eprotsen          #+#    #+#             */
/*   Updated: 2022/12/25 14:47:56 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

//every struct field except chars_printed is set to 0
void	clear_struct(t_count *print)
{
	print->format_char = 0;
	print->type_c = 0;
	print->type_u = 0;
	print->type_s = 0;
	print->type_d_i = 0;
	print->type_x_x = 0;
	print->type_p = 0;
}

void	print_format_string(const char *s, t_count *print, va_list args)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			print->format_char = s[i];
			print_arg(print, args);
			clear_struct(print);
		}
		else
			printf_putchar(print, s[i], 1);
		i++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_count		*print;

	print = hmalloc(sizeof(t_count));
	if (print == NULL)
		return (-1);
	clear_struct(print);
	print->chars_printed = 0;
	va_start(args, s);
	print_format_string(s, print, args);
	va_end(args);
	hfree(print);
	return (print->chars_printed);
}
