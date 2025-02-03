/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:34:45 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/02/03 15:27:09 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:34:45 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/02/03 12:48:57 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	check_dead(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->data->dead_lock);
	is_dead = philo->data->dead;
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (is_dead);
}

void	check_sleep(t_philo *philo)
{
	info("is sleeping.", philo);
	usleep(philo->data->sleep_time * 1000);
	if (check_dead(philo))
		return ;
}

void	check_think(t_philo *philo)
{
	info("is thinking.", philo);
	usleep(1000);
	if (check_dead(philo))
		return ;
}

void	*routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	eat(philo);
	meals(philo);
	if (philo->data->meals_required != -1 && philo->eat_cont
		>= philo->data->meals_required)
		return (NULL);
	while (1)
	{
		if (check_dead(philo))
			break ;
		check_sleep(philo);
		if (check_dead(philo))
			break ;
		check_think(philo);
		if (check_dead(philo))
			break ;
		eat(philo);
		meals(philo);
	}
	return (NULL);
}
