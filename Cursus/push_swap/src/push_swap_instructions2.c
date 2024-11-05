/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:15:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/10/24 00:13:33 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list **list, t_list **c, int a)
{
	t_list	*first;
	t_list	*temp;

	first = *list;
	temp = (*list)->next;
	while ((*list)->next != NULL)
		*list = (*list)->next;
	(*list)->next = first;
	first->next = NULL;
	*list = temp;
	temp = *list;
	position(list, c);
	if (a == 0)
		ft_printf("r%c\n", (*list)->box);
	return (1);
}

int	ft_rot_rot(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	int	a;

	a = 0;
	a = ft_rotate(x, c_x, 1);
	a = ft_rotate(y, c_y, 1);
	ft_printf("rr\n");
	return (a);
}

int	ft_rrotate(t_list **list, t_list **c, int a)
{
	t_list	*second_last;
	t_list	*last;

	second_last = NULL;
	last = *list;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *list;
	*list = last;
	last = *list;
	position(list, c);
	if (a == 0)
		ft_printf("rr%c\n", (*list)->box);
	return (1);
}

int	ft_rrot_rrot(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	int	a;

	a = 0;
	a = ft_rrotate(x, c_x, 1);
	a = ft_rrotate(y, c_y, 1);
	ft_printf("rrr\n");
	return (a);
}

int	ft_push(t_list **x, t_list **y, t_list **c_x, t_list **c_y)
{
	t_list	*first_y;
	t_list	*temp;

	temp = (*y)->next;
	first_y = *y;
	first_y->next = *x;
	if (first_y->box == 'a')
		first_y->box = 'b';
	else
		first_y->box = 'a';
	(*x) = first_y;
	*y = (*y)->next;
	*y = temp;
	position(x, c_x);
	position(y, c_y);
	ft_printf("p%c\n", (*x)->box);
	return (1);
}
