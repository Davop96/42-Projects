/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:03:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/10/25 10:55:39 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_prep_cost_no_max(t_list *x, t_list *y)
{
	t_list	*t2;
	int		fi;
	int		max;

	t2 = y;
	fi = x->index + 1;
	max = max_index(y);
	while (fi <= max)
	{
		while (y->index != fi && y->next != NULL)
			y = y->next;
		if (y->index == fi)
		{
			x->prev = y->pos;
			y = t2;
			break ;
		}
		y = t2;
		fi++;
	}
}

void	ft_prep_cost(t_list *x, t_list *y)
{
	t_list	*t1;
	t_list	*t2;

	t1 = x;
	t2 = y;
	while (x != NULL)
	{
		if (x->index > max_index(y))
		{
			while (y->index != min_index(y))
				y = y->next;
			x->prev = y->pos;
			y = t2;
		}
		else
			ft_prep_cost_no_max(x, y);
		x = x->next;
	}
	x = t1;
}

void	ft_cost(t_list *x, t_list *y)
{
	t_list	*t1;
	int		sy;
	int		sx;

	ft_prep_cost(x, y);
	sy = ft_size(y);
	sx = ft_size(x);
	t1 = x;
	while (x != NULL)
	{
		if (x->prev <= (sy / 2) && (x->pos <= (sx / 2) || sx == 1))
			x->cost = (x->prev - 1) + (x->pos - 1) + 1;
		else if (x->prev <= (sy / 2) && x->pos > (sx / 2))
			x->cost = (x->prev - 1) + (sx - x->pos + 1) + 1;
		else if (x->prev > (sy / 2) && (x->pos <= (sx / 2) || sx == 1))
			x->cost = (sy - x->prev + 1) + (x->pos - 1) + 1;
		else if (x->prev > (sy / 2) && x->pos > (sx / 2))
			x->cost = (sy - x->prev + 1) + (sx - x->pos + 1) + 1;
		x = x->next;
	}
	x = t1;
}

int	ft_mov1_1(t_list **x, int *m)
{
	int		i;
	t_list	**c_x;

	i = 0;
	c_x = x;
	m[1] = m[1] - m[0];
	while (m[1]-- > 0)
		i += ft_rotate(x, c_x, 0);
	return (i);
}

int	ft_mov1(t_list **x, t_list **y, int *p, int *s)
{
	int		i;
	int		m[2];
	t_list	**c_x;
	t_list	**c_y;

	i = 0;
	c_x = x;
	c_y = y;
	m[0] = min(p[1] - 1, p[0] - 1);
	m[1] = max(p[1] -1, p[0] - 1);
	while (m[0]-- > 0)
		i += ft_rot_rot(x, y, c_x, c_y);
	m[0] = min(p[1] - 1, p[0] - 1);
	if (m[1] == p[1] - 1)
		i += ft_mov1_1(y, m);
	else if (m[1] == p[0] - 1)
		i += ft_mov1_1(x, m);
	if (s[1] == 1)
		return (i);
	else
		i += ft_push(y, x, c_y, c_x);
	return (i);
}
