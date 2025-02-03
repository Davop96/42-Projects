/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:50:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/01/31 15:19:57 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	init_forks(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->philo_num)
	{
		if (pthread_mutex_init(&data->forks[x], NULL) != 0)
		{
			error("Mutex initialization failure for forks", data);
			return (1);
		}
	}
	return (0);
}

void	init_philosophers(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->philo_num)
	{
		data->philos[x].id = x;
		data->philos[x].data = data;
		data->philos[x].l_fork = &data->forks[x];
		data->philos[x].r_fork = &data->forks[(x + 1) % data->philo_num];
		data->philos[x].time_to_die = get_time();
		pthread_mutex_init(&data->philos[x].lock, NULL);
	}
}

void	init_philos(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->philo_num)
	{
		data->philos[x].id = x;
		data->philos[x].data = data;
		data->philos[x].l_fork = &data->forks[x];
		data->philos[x].r_fork = &data->forks[(x + 1) % data->philo_num];
		data->philos[x].time_to_die = get_time();
		data->philos[x].eat_cont = 0;
		pthread_mutex_init(&data->philos[x].lock, NULL);
	}
}

int	init_data(t_data *data, char **av, int ac)
{
	if (check_init(data))
		return (1);
	if (ac != 5 && ac != 6)
	{
		error("Arguments invalid", NULL);
		return (1);
	}
	data->philo_num = ft_atoi(av[1]);
	data->death_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_required = ft_atoi(av[5]);
	else
		data->meals_required = -1;
	data->dead = 0;
	data->finished = 0;
	data->philos = NULL;
	data->forks = NULL;
	data->tid = NULL;
	data->start_time = get_time();
	return (0);
}

int	init(t_data *data, char **av, int ac)
{
	if (init_data(data, av, ac))
		return (1);
	if (alloc(data))
		return (1);
	if (init_forks(data))
		return (1);
	if (pthread_mutex_init(&data->print_lock, NULL))
	{
		error("Mutex initialization failure for print_lock", data);
		return (1);
	}
	if (thread_init(data))
		return (1);
	return (0);
}
