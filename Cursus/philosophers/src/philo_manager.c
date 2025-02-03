/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:33:54 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/02/03 15:15:58 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	check_philosopher_death(t_philo *philo)
{
	uint64_t	current_time;

	pthread_mutex_lock(&philo->lock);
	if (get_time() - philo->time_to_die > philo->data->death_time)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		pthread_mutex_lock(&philo->data->dead_lock);
		if (!philo->data->dead)
		{
			current_time = get_elapsed_time(philo->data->start_time);
			printf("%lu Philosopher %d has died.\n",
				current_time + 1, philo->id + 1);
			philo->data->dead = 1;
		}
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo->data->print_lock);
		pthread_mutex_unlock(&philo->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->lock);
	return (0);
}

void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (1)
	{
		check_philosopher_death(philo);
		pthread_mutex_lock(&philo->data->dead_lock);
		if (philo->data->dead)
		{
			pthread_mutex_unlock(&philo->data->dead_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->data->dead_lock);
		usleep(1000);
	}
	return (NULL);
}

void	*monitor(void *data_pointer)
{
	t_data		*data;
	int			x;

	data = (t_data *)data_pointer;
	while (1)
	{
		x = -1;
		while (++x < data->philo_num)
		{
			pthread_mutex_lock(&data->philos[x].lock);
			if (get_time() - data->philos[x].time_to_die > data->death_time)
			{
				data->dead = 1;
				pthread_mutex_unlock(&data->philos[x].lock);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philos[x].lock);
		}
		usleep(1000);
	}
	return (NULL);
}

uint64_t	get_elapsed_time(uint64_t start_time)
{
	return (get_time() - start_time);
}

uint64_t	get_time(void)
{
	struct timeval	tv;
	uint64_t		time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms);
}
