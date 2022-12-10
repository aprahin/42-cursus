/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:25:49 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/10 14:44:25 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logs(char *msg, int id)
{
	printf("%i %i %s\n", get_time(), id, msg);
}

int	get_time(void)
{
	static int		start = -1;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (start < 0)
		start = time.tv_sec;
	return ((time.tv_sec - start) * 1000 + time.tv_usec / 1000);
}
