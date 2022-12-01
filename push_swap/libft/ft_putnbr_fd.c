/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:06:15 by aprahin           #+#    #+#             */
/*   Updated: 2022/10/31 11:36:43 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	set_stuff(int *i, int *pm, int *n)
{
	*i = 0;
	if (*n < 0)
	{
		*pm = 1;
		*n = -(*n);
	}
	else
	{
		*pm = 0;
	}
	return ;
}

static int	check_edge(int n, int fd)
{	
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	a[13];
	int		pm;
	int		i;
	int		m;

	if (check_edge(n, fd))
		return ;
	if (n < 0)
		a[0] = '-';
	set_stuff(&i, &pm, &n);
	m = n;
	while (m > 0)
	{
		m /= 10;
		i++;
	}
	m = i;
	while (i > 0)
	{
		a[i - 1 + pm] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	write(fd, (void *) a, m + pm);
}
