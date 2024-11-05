/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:06:40 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/10/29 16:30:18 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_step(t_list **a, t_list **b, t_list **c_a, t_list **c_b)
{
	int	s;
	int	i;
	int	j;

	j = 0;
	i = 0;
	s = ft_size(*a);
	while (i < (s - 3))
	{
		if ((*a)->index > (s / 2))
			j += ft_push(b, a, c_b, c_a);
		else
			j += ft_rotate(a, c_a, 0);
		i++;
	}
	s = ft_size(*a);
	i = 0;
	while (i < (s - 3))
	{
		j += ft_push(b, a, c_b, c_a);
		i++;
	}
	return (j);
}

void	sort_three(t_list **x, t_list **c)
{
	if ((*x)->index < (*x)->next->index && (*x)->index < (*x)->next->next->index
		&& (*x)->next->index > (*x)->next->next->index)
	{
		ft_swap(x, c, 0);
		ft_rotate(x, c, 0);
	}
	else if ((*x)->index > (*x)->next->index
		&& (*x)->index < (*x)->next->next->index
		&& (*x)->next->index < (*x)->next->next->index)
		ft_swap(x, c, 0);
	else if ((*x)->index < (*x)->next->index
		&& (*x)->index > (*x)->next->next->index
		&& (*x)->next->index > (*x)->next->next->index)
		ft_rrotate(x, c, 0);
	else if ((*x)->index > (*x)->next->index
		&& (*x)->index > (*x)->next->next->index
		&& (*x)->next->index < (*x)->next->next->index)
		ft_rotate(x, c, 0);
	else if ((*x)->index > (*x)->next->index
		&& (*x)->index > (*x)->next->next->index
		&& (*x)->next->index > (*x)->next->next->index)
	{
		ft_swap(x, c, 0);
		ft_rrotate(x, c, 0);
	}
}

int	ft_mov(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	int	i;
	int	p;

	i = 0;
	p = min_cost(*x);
	if (p == 1)
		i += ft_push(y, x, c_y, c_x);
	else
		i += ft_prep_mov_2(x, y);
	return (i);
}

int	ft_last_rotation(t_list **x, t_list **c_x)
{
	int		psr[3];
	int		i;
	t_list	*temp;

	i = 0;
	temp = *x;
	psr[1] = ft_size(*x);
	while ((*x)->index != 1)
		*x = (*x)->next;
	psr[0] = (*x)->pos;
	*x = temp;
	if (psr[0] <= psr[1] / 2)
	{
		psr[2] = psr[0] - 1;
		while (psr[2]-- > 0)
			i += ft_rotate(x, c_x, 0);
	}
	else
	{
		psr[2] = psr[1] - psr[0] + 1;
		while (psr[2]-- > 0)
			i += ft_rrotate(x, c_x, 0);
	}
	return (i);
}

int	ft_push_swap(t_list **a, t_list **b)
{
	int		j;
	t_list	*current_a;
	t_list	*current_b;

	current_a = *a;
	current_b = *b;
	j = 0;
	if (ft_size(*a) == 1 || ft_size(*a) == 2)
	{
		if (ft_size(*a) == 2 && (*a)->value > (*a)->next->value)
			j += ft_swap(a, &current_a, 0);
		return (j);
	}
	j += first_step(a, b, &current_a, &current_b);
	sort_three(a, &current_a);
	while (ft_size(*b) >= 1)
	{
		ft_cost(*b, *a);
		j += ft_mov(b, a, &current_b, &current_a);
	}
	j += ft_last_rotation(a, &current_a);
	ft_free(a);
	return (j);
}
