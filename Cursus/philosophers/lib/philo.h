/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:37:08 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/02/03 15:24:11 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	pthread_t		supervisor_thread;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_num;
	int				dead;
	int				finished;
	int				meals_required;
	t_philo			*philos;
	uint64_t		death_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	finished_lock;
}	t_data;

//Utilities
int			ft_isdigit(int c);
int			is_number(char *str);
int			ft_atoi(char *str);
long		ft_atol(char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_exit(t_data *data);
void		clear_data(t_data *data);
int			error(char *str, t_data *data);

//Checker
int			check_philosopher_count(int ac, char **av);
int			check_number_range(int ac, char **av);
int			check_valid_arguments(int ac, char **av);
int			check_arguments(int ac, char **av);
int			check_init(t_data *data);

//Init
void		init_philosophers(t_data *data);
int			init_forks(t_data *data);
void		init_philos(t_data *data);
int			init_data(t_data *data, char **av, int ac);
int			init(t_data *data, char **av, int ac);

//Routine
int			check_dead(t_philo *philo);
void		check_sleep(t_philo *philo);
void		check_think(t_philo *philo);
void		*routine(void *philo_pointer);

//Manager
int			check_philosopher_death(t_philo *philo);
void		*supervisor(void *philo_pointer);
void		*monitor(void *data_pointer);
uint64_t	get_time(void);
uint64_t	get_elapsed_time(uint64_t start_time);

//Threads
int			create_threads(t_data *data);
int			thread_init(t_data *data);
int			alloc_philos(t_data *data);
int			alloc_forks_and_tid(t_data *data);
int			alloc(t_data *data);

//Actions
void		info(char *str, t_philo *philo);
void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		eat(t_philo *philo);
void		meals(t_philo *philo);

#endif