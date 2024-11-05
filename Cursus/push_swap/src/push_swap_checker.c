/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:23:08 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/11/04 12:51:34 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_validation(t_list **a, char **res, int ac, char **av)
{
	int		x;
	t_list	*c_a;

	x = 0;
	c_a = *a;
	while (*a != NULL)
	{
		if ((*a)->index == (*a)->pos)
			x++;
		*a = (*a)->next;
	}
	*a = c_a;
	if (x == ft_size(*a))
	{
		if (ac == 2)
			free_split(res, malloc_size(av[1], ' '));
		else
			free(res);
		ft_free(a);
		exit (0);
	}
}

int	ft_valid_arg(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	if (ac == 2)
		return (k);
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '\0')
			k = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == ' ')
				k = 0;
			j++;
		}
		i++;
	}
	if (k == 0)
		write(2, "Error\n", 6);
	return (k);
}

int	is_invalid_format(const char *arg)
{
	int	x;

	x = 0;
	if ((arg[0] == '-' && arg[1] == '\0') || (arg[0] == '+' && arg[1] == '\0'))
		return (1);
	while (arg[x] != '\0')
	{
		if ((arg[x] == '-' && arg[x + 1] == '-')
			|| (arg[x] == '+' && arg[x + 1] == '+'))
		{
			return (1);
		}
		if (ft_isdigit(arg[x]) && (arg[x + 1] == '-' || arg[x + 1] == '+'))
		{
			return (1);
		}
		x++;
	}
	return (0);
}

int	validate_arguments(int ac, char **av)
{
	int	x;

	x = 1;
	if (ac <= 1)
		return (0);
	if (av[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (x < ac)
	{
		if (is_invalid_format(av[x]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		x++;
	}
	return (2);
}

int	initialize_and_validate(int ac, char **av, char ***res)
{
	int	validation_result;

	validation_result = validate_arguments(ac, av);
	if (validation_result != 2)
		return (validation_result);
	*res = ft_creator(ac, av);
	if (ft_not_alpha(*res) == 0 || ft_number(*res) == 0
		|| ft_valid_arg(ac, av) == 0)
	{
		if (ac == 2)
			free_split(*res, malloc_size(av[1], ' '));
		else
			free(*res);
		return (0);
	}
	return (2);
}
