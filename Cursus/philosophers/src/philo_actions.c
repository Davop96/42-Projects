/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:41:56 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/02/03 12:39:30 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

void	info(char *str, t_philo *philo)
{
	uint64_t	current_time;

	current_time = get_elapsed_time(philo->data->start_time);
	pthread_mutex_lock(&philo->data->print_lock);
	if (!philo->data->dead)
	{
		if (philo->data->philo_num == 1
			&& ft_strcmp(str, "has died alone.") == 0)
			printf("%lu Philosopher %d %s\n", current_time + 1,
				philo->id + 1, str);
		else
			printf("%lu %d %s\n", current_time, philo->id + 1, str);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	take_forks(t_philo *philo)
{
	if (philo->data->philo_num == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		info("has taken the left fork.", philo);
		usleep(philo->data->death_time * 1000);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		info("has taken the left fork.", philo);
		usleep(40);
		pthread_mutex_lock(philo->r_fork);
		info("has taken the right fork.", philo);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		info("has taken the right fork.", philo);
		usleep(60);
		pthread_mutex_lock(philo->l_fork);
		info("has taken the left fork.", philo);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	info("is eating.", philo);
	pthread_mutex_lock(&philo->lock);
	philo->time_to_die = get_time();
	pthread_mutex_unlock(&philo->lock);
	usleep(philo->data->eat_time * 1000);
	drop_forks(philo);
}

void	meals(t_philo *philo)
{
	uint64_t	current_time;

	philo->eat_cont++;
	if (philo->data->meals_required != -1 && philo->eat_cont
		>= philo->data->meals_required)
	{
		pthread_mutex_lock(&philo->data->finished_lock);
		philo->data->finished++;
		if (philo->data->finished >= philo->data->philo_num)
		{
			pthread_mutex_lock(&philo->data->print_lock);
			pthread_mutex_lock(&philo->data->dead_lock);
			if (!philo->data->dead)
			{
				current_time = get_elapsed_time(philo->data->start_time);
				printf("%lu Philosophers have eaten %d times.\n",
					current_time, philo->data->meals_required);
				philo->data->dead = 1;
			}
			pthread_mutex_unlock(&philo->data->dead_lock);
			pthread_mutex_unlock(&philo->data->print_lock);
		}
		pthread_mutex_unlock(&philo->data->finished_lock);
	}
}
