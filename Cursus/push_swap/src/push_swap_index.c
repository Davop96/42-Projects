/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:16:42 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/10/23 17:39:22 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(t_list *x)
{
	int		max;
	t_list	*t;

	max = x->index;
	t = x;
	while (x->next != NULL)
	{
		if (x->next->index > max)
			max = x->next->index;
		x = x->next;
	}
	x = t;
	return (max);
}

int	min_index(t_list *x)
{
	int		min;
	t_list	*t;

	min = x->index;
	t = x;
	while (x->next != NULL)
	{
		if (x->next->index < min)
			min = x->next->index;
		x = x->next;
	}
	x = t;
	return (min);
}

int	min_cost(t_list *x)
{
	int		min;
	t_list	*t;

	min = x->cost;
	t = x;
	while (x->next != NULL)
	{
		if (x->next->cost < min)
			min = x->next->cost;
		x = x->next;
	}
	x = t;
	return (min);
}

int	min_cost_min_index(t_list *x, int c)
{
	int		min;
	t_list	*t;

	t = x;
	while (x->cost != c)
		x = x->next;
	min = x->index;
	x = t;
	while (x != NULL)
	{
		if (x->cost == c && x->index < min)
			min = x->index;
		x = x->next;
	}
	x = t;
	return (min);
}

int	ft_size(t_list *list)
{
	int		x;
	t_list	*temp;

	x = 0;
	temp = list;
	while (list != NULL)
	{
		x++;
		list = list->next;
	}
	list = temp;
	return (x);
}
