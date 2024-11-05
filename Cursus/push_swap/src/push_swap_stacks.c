/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:46:54 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/11/05 11:03:31 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_creator(int argc, char **argv)
{
	int		y;
	char	**res;

	if (argc == 2)
		res = ft_split(argv[1], ' ');
	else
	{
		res = malloc(argc * sizeof(char *));
		if (!res)
			return (NULL);
		y = 1;
		while (y < argc)
		{
			res[y - 1] = argv[y];
			y++;
		}
		res[y - 1] = NULL;
	}
	return (res);
}

t_list	*new_num(int val, int index, int pos, char box)
{
	t_list	*num;

	num = (t_list *)malloc(sizeof(t_list));
	if (num != NULL)
	{
		num->value = val;
		num->index = index;
		num->pos = pos;
		num->box = box;
		num->cost = 0;
		num->prev = 0;
		num->next = NULL;
	}
	return (num);
}

int	ft_not_alpha(char **res)
{
	int	y;
	int	x;

	y = 0;
	while (res[y] != NULL)
	{
		x = 0;
		while (x < ft_strlen(res[y]))
		{
			if (ft_isalpha(res[y][x]) == 1)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_number(char **res)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	z = 1;
	while (res[x] != NULL)
	{
		if (ft_atoi(res[x]) > 2147483647 || ft_atoi(res[x]) < -2147483648)
			z = 0;
		y = x + 1;
		while (res[y] != NULL)
		{
			if (ft_atoi(res[x]) == ft_atoi(res[y]))
				z = 0;
			y++;
		}
		x++;
	}
	if (z == 0)
		write(2, "Error\n", 6);
	return (z);
}

void	fill_sort_index_a(t_list **a, char **res, int ac, char **av)
{
	int		x;
	t_list	*c_a;

	c_a = *a;
	x = 1;
	while (res[x] != NULL)
	{
		(*a)->next = new_num(ft_atoi(res[x]), x + 1, x + 1, 'a');
		*a = (*a)->next;
		if (ac == 2)
			free(res[x]);
		x++;
	}
	*a = c_a;
	sort_index(*a);
	ft_first_validation(a, res, ac, av);
	free(res);
}
