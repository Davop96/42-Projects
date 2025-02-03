/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:36:27 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/01/31 17:10:27 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

void	clear_data(t_data	*data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}

void	ft_exit(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[x]);
		pthread_mutex_destroy(&data->philos[x].lock);
	}
	pthread_mutex_destroy(&data->print_lock);
	clear_data(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		x;

	x = -1;
	if (check_arguments(ac, av))
		return (1);
	if (init(&data, av, ac))
		return (1);
	while (++x < data.philo_num)
	{
		pthread_join(data.philos[x].t1, NULL);
		pthread_join(data.philos[x].supervisor_thread, NULL);
	}
	ft_exit(&data);
	return (0);
}
