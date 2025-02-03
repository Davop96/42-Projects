/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:55:09 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/02/03 11:10:29 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(char *str)
{
	int	x;

	x = 0;
	if (str[x] == '-' || str[x] == '+')
		x++;
	while (str[x])
	{
		if (!ft_isdigit(str[x]))
			return (0);
		x++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int		x;
	int		res;
	int		sign;

	x = 0;
	sign = 1;
	res = 0;
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	while (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = res * 10 + (str[x] - '0');
		x++;
	}
	return (sign * res);
}

long	ft_atol(char *str)
{
	int		x;
	long	res;
	int		sign;

	x = 0;
	sign = 1;
	res = 0;
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	while (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		res = res * 10 + (str[x] - '0');
		x++;
	}
	return (sign * res);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
	{
		x++;
	}
	return (s1[x] - s2[x]);
}
