/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:23:14 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/09 22:31:29 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_forks_mutex(t_philo *p)
{
	if (p->next_m && p->next_f && p->prev_m && p->prev_f)
		return (0);
	if (p->next_m)
		free(p->next_m);
	p->next_m = NULL;
	if (p->next_f)
		free(p->next_f);
	p->next_f = NULL;
	if (p->prev_m)
		free(p->prev_m);
	p->prev_m = NULL;
	if (p->prev_f)
		free(p->prev_f);
	p->prev_f = NULL;
	return (1);
}

int	alloc_forks(t_philo **p, char **av, int i)
{
	if (i + 1 == 1)
	{
		p[i]->prev_m = malloc(sizeof(pthread_mutex_t));
		p[i]->prev_f = malloc(sizeof(int));
	}
	else
	{
		p[i]->prev_m = p[i - 1]->next_m;
		p[i]->prev_f = p[i - 1]->next_f;
	}
	if (i + 1 == ft_atoi(av[1]))
	{
		p[i]->next_m = p[0]->prev_m;
		p[i]->next_f = p[0]->prev_f;
	}
	else
	{
		p[i]->next_m = malloc(sizeof(pthread_mutex_t));
		p[i]->next_f = malloc(sizeof(int));
	}
	p[i]->forks = 0;
	return (check_forks_mutex(p[i]));
}

void	take_fork(t_philo *p)
{
	pthread_mutex_lock(p->prev_m);
	if (*(p->prev_f) == 1)
	{
		p->forks += 1;
		*(p->prev_f) -= 1;
		logs("has taken a fork", p->id);
	}
	pthread_mutex_unlock(p->prev_m);
	if (p->forks == 2)
		return ;
	pthread_mutex_lock(p->next_m);
	if (*(p->next_f) == 1)
	{
		p->forks += 1;
		*(p->next_f) -= 1;
		logs("has taken a fork", p->id);
	}
	pthread_mutex_unlock(p->next_m);
}

void	release_fork(t_philo *p)
{
	pthread_mutex_lock(p->prev_m);
	p->forks -= 1;
	*(p->prev_f) += 1;
	pthread_mutex_unlock(p->prev_m);
	pthread_mutex_lock(p->next_m);
	p->forks -= 1;
	*(p->next_f) += 1;
	pthread_mutex_unlock(p->next_m);
}
