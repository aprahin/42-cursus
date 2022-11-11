/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:14:50 by aprahin           #+#    #+#             */
/*   Updated: 2022/11/05 22:14:50 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(const char c);
int		ft_putstr(const char *s);
void	ft_putnbr(int n);
int		ft_in(const char c, const char *set);
int		ft_parse(const char *f, char **p);
int		ft_printnbr(const char *flags, int width, int prec, va_list args);
int		ft_printhex(const char *flags, int width, int prec, va_list args);
int		ft_printstr(const char *flags, int width, int prec, va_list args);
int		ft_printchar(const char *flags, int width, va_list args);
int		ft_printptr(const char *flags, int width, va_list args);
int		ft_printpc(const char *flags, int width);
void	ft_addchar(char **str, char c, int start);
void	ft_removechar(char	**str, const char *charset);
char	*ft_itoh(int n, const char *hex);
char	*ft_utoa(unsigned int n);

#endif