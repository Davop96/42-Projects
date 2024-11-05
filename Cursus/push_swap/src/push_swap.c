/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:56:45 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/11/04 16:59:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**res;
	t_list	*a;
	t_list	*b;
	int		init_result;

	init_result = initialize_and_validate(ac, av, &res);
	if (init_result != 2)
		return (init_result);
	b = NULL;
	a = new_num(ft_atoi(res[0]), 1, 1, 'a');
	fill_sort_index_a(&a, res, ac, av);
	ft_push_swap(&a, &b);
	return (0);
}
