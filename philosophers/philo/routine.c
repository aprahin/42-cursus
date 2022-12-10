/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:20:46 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/10 23:01:23 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die(t_philo *p)
{
	if (get_time() - p->die > p->last)
	{
		logs("died", p->id);
		*(p->stop) = 1;
	}
}

void	think(t_philo *p)
{
	if (*(p->stop))
		return ;
	logs("is thinking", p->id);
	while (!(*(p->stop)) && p->forks < 2)
	{
		take_fork(p);
		die(p);
	}
}

void	eat(t_philo *p)
{
	if (*(p->goal) == 0)
		*(p->stop) = 1;
	if (*(p->stop))
	{
		release_fork(p);
		return ;
	}
	logs("is eating", p->id);
	p->last = get_time();
	while (!(*(p->stop)) && get_time() < p->last + p->eat)
		die(p);
	release_fork(p);
	if (*(p->goal) != -1 && p->max_eat > 0)
	{
		pthread_mutex_lock(p->goal_m);
		*(p->goal) -= 1;
		if (*(p->goal) <= 0)
			*(p->stop) = 1;
		pthread_mutex_unlock(p->goal_m);
		p->max_eat -= 1;
	}
}

void	dream(t_philo *p)
{
	int	tmp;

	if (*(p->stop))
		return ;
	tmp = get_time();
	logs("is sleeping", p->id);
	while (!(*(p->stop)) && get_time() < tmp + p->slp)
		die(p);
}

void	*routine(void *passed)
{
	t_philo	*p;

	p = (t_philo *) passed;
	if ((p->id - 1) % 2 == 1)
		usleep(30000);
	while (!*(p->stop))
	{
		die(p);
		think(p);
		eat(p);
		dream(p);
	}
	return (NULL);
}
