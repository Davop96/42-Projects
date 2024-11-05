/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:15:04 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/10/24 00:13:25 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mov2(t_list **x, t_list **y, int *p, int *s)
{
	int		i;
	int		m[2];
	t_list	**c_x;
	t_list	**c_y;

	i = 0;
	c_x = x;
	c_y = y;
	m[0] = p[1] - 1;
	m[1] = s[1] - p[0] + 1;
	while (m[0]-- > 0)
		i += ft_rotate(y, c_y, 0);
	while (m[1]-- > 0)
		i += ft_rrotate(x, c_x, 0);
	i += ft_push(y, x, c_y, c_x);
	return (i);
}

int	ft_mov3(t_list **x, t_list **y, int *p, int *s)
{
	int		i;
	int		m[2];
	t_list	**c_x;
	t_list	**c_y;

	i = 0;
	c_x = x;
	c_y = y;
	m[0] = s[0] - p[1] + 1;
	m[1] = p[0] - 1;
	while (m[0]-- > 0)
		i += ft_rrotate(y, c_y, 0);
	while (m[1]-- > 0)
		i += ft_rotate(x, c_x, 0);
	if (s[1] == 1)
		return (i);
	else
		i += ft_push(y, x, c_y, c_x);
	return (i);
}

int	ft_mov4_1(t_list **x, int *m)
{
	int		i;
	t_list	**c_x;

	i = 0;
	c_x = x;
	m[1] = m[1] - m[0];
	while (m[1]-- > 0)
		i += ft_rrotate(x, c_x, 0);
	return (i);
}

int	ft_mov4(t_list **x, t_list **y, int *p, int *s)
{
	int		i;
	int		m[2];
	t_list	**c_x;
	t_list	**c_y;

	i = 0;
	c_x = x;
	c_y = y;
	m[0] = min(s[0] - p[1] + 1, s[1] - p[0] + 1);
	m[1] = max(s[0] - p[1] + 1, s[1] - p[0] + 1);
	while (m[0]-- > 0)
		i += ft_rrot_rrot(x, y, c_x, c_y);
	m[0] = min(s[0] - p[1] + 1, s[1] - p[0] +1);
	if (m[1] == s[0] - p[1] + 1)
		i += ft_mov4_1(y, m);
	else if (m[1] == s[1] - p[0] + 1)
		i += ft_mov4_1(x, m);
	i += ft_push(y, x, c_y, c_x);
	return (i);
}

int	ft_prep_mov_2(t_list **x, t_list **y)
{
	int	i;
	int	p[2];
	int	s[2];

	i = 0;
	s[0] = ft_size(*y);
	s[1] = ft_size(*x);
	p[0] = min_cost(*x);
	p[0] = min_cost_min_index(*x, p[0]);
	ft_prev_pos(x, p);
	if (p[1] <= (s[0] / 2) && (p[0] <= (s[1] / 2) || s[1] == 1))
		i += ft_mov1(x, y, p, s);
	else if (p[1] <= (s[0] / 2) && p[0] > (s[1] / 2))
		i += ft_mov2(x, y, p, s);
	else if (p[1] > (s[0] / 2) && (p[0] <= (s[1] / 2) || s[1] == 1))
		i += ft_mov3(x, y, p, s);
	else if (p[1] > (s[0] / 2) && p[0] > (s[1] / 2))
		i += ft_mov4(x, y, p, s);
	return (i);
}
