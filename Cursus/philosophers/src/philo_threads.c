/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:34:02 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/01/31 15:28:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	create_threads(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->philo_num)
	{
		if (pthread_create(&data->philos[x].t1, NULL
				, &routine, &data->philos[x]) != 0)
		{
			error("Failed to create philosopher thread", data);
			return (1);
		}
		if (pthread_create(&data->philos[x].supervisor_thread, NULL
				, &supervisor, &data->philos[x]) != 0)
		{
			error("Failed to create supervisor thread", data);
			return (1);
		}
	}
	return (0);
}

int	thread_init(t_data *data)
{
	if (data->philo_num == 1)
	{
		data->philos[0].id = 0;
		data->philos[0].data = data;
		data->philos[0].l_fork = &data->forks[0];
		data->philos[0].r_fork = &data->forks[0];
		data->philos[0].time_to_die = get_time();
		pthread_mutex_lock(&data->forks[0]);
		info("has taken the left fork.", &data->philos[0]);
		usleep(data->death_time * 1000);
		info("has died alone.", &data->philos[0]);
		pthread_mutex_unlock(&data->forks[0]);
		ft_exit(data);
		return (1);
	}
	init_philosophers(data);
	if (create_threads(data))
		return (1);
	return (0);
}

int	alloc_philos(t_data *data)
{
	int	x;

	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
	{
		error("Memory allocation failure for philos", data);
		return (1);
	}
	x = 0;
	while (x < data->philo_num)
	{
		data->philos[x].lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		data->philos[x].eat_cont = 0;
		x++;
	}
	return (0);
}

int	alloc_forks_and_tid(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
	{
		error("Memory allocation failure for forks", data);
		return (1);
	}
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
	{
		error("Memory allocation failure for tid", data);
		return (1);
	}
	return (0);
}

int	alloc(t_data *data)
{
	if (alloc_philos(data))
		return (1);
	if (alloc_forks_and_tid(data))
		return (1);
	return (0);
}
