/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:21:45 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/10/23 17:39:52 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(t_list **list, t_list **c)
{
	int		x;
	t_list	*temp;

	temp = *list;
	x = 1;
	while (*list != NULL)
	{
		(*list)->pos = x;
		x++;
		*list = (*list)->next;
	}
	*list = temp;
	*c = *list;
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_prev_pos(t_list **x, int *p)
{
	t_list	*t;

	t = *x;
	while ((*x)->index != p[0])
		*x = (*x)->next;
	p[0] = (*x)->pos;
	p[1] = (*x)->prev;
	*x = t;
}

void	ft_free(t_list **x)
{
	t_list	*temp;

	while (*x != NULL)
	{
		temp = (*x)->next;
		free(*x);
		*x = temp;
	}
}
