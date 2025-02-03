/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:28:29 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/02/03 11:06:35 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	check_philosopher_count(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		error("Invalid number of arguments.", NULL);
		return (1);
	}
	if (ft_atoi(av[1]) == 0)
	{
		printf("There aren't any philosophers here, check somewhere else.\n");
		return (1);
	}
	if (ft_atoi(av[1]) < 0)
	{
		printf("There can't be negatives philosophers, even they know that.\n");
		return (1);
	}
	return (0);
}

int	check_number_range(int ac, char **av)
{
	int		x;
	long	num;

	x = 1;
	while (x < ac)
	{
		num = ft_atol(av[x]);
		if (num < INT_MIN || num > INT_MAX)
		{
			printf("You can't use that number.\n");
			return (1);
		}
		x++;
	}
	return (0);
}

int	check_valid_arguments(int ac, char **av)
{
	int	x;

	x = 1;
	while (x < ac)
	{
		if (!is_number(av[x]))
		{
			error("Arguments must be numbers only.", NULL);
			return (1);
		}
		if (ft_atoi(av[x]) < 0)
		{
			printf("Argument %d can't be negative.\n", x);
			return (1);
		}
		if (av[x][0] == '\0' || ft_strcmp(av[x], " ") == 0)
		{
			printf("Argument %d can't be empty or a space.\n", x);
			return (1);
		}
		x++;
	}
	return (0);
}

int	check_arguments(int ac, char **av)
{
	if (check_philosopher_count(ac, av))
		return (1);
	if (check_number_range(ac, av))
		return (1);
	if (check_valid_arguments(ac, av))
		return (1);
	return (0);
}

int	check_init(t_data *data)
{
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
	{
		error("Mutex initialization failure for dead_lock", data);
		return (1);
	}
	if (pthread_mutex_init(&data->finished_lock, NULL) != 0)
	{
		error("Mutex initialization failure for finished_lock", data);
		return (1);
	}
	return (0);
}
