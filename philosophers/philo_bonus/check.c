/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:37:22 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/10 14:38:26 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_stop(void *passed)
{
	t_philo	*p;

	p = (t_philo *) passed;
	sem_wait(p->stop_s);
	*(p->stop) = 1;
	sem_post(p->stop_s);
	sem_post(p->fork_s);
	return (NULL);
}

void	*check_die(void *passed)
{
	t_philo	*p;

	p = (t_philo *) passed;
	while (1)
	{
		if (*(p->stop))
			return (NULL);
		if (p->last + p->die < get_time())
		{
			logs("has died", p->id);
			break ;
		}
	}
	sem_post(p->stop_s);
	return (NULL);
}

void	*check_goal(void *passed)
{
	t_philo	*p;

	p = (t_philo *) passed;
	while (1)
	{
		sem_wait(p->goal_s);
		if (*(p->stop))
			break ;
		p->goal -= 1;
		if (p->goal == 0)
		{
			sem_post(p->stop_s);
			break ;
		}
	}
	return (NULL);
}
