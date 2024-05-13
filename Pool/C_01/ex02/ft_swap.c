/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:24:43 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 13:16:41 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 4;
	b = 2;
	ft_swap(&a, &b);
	printf("The value of a is: " "%d\n", a);
	printf("The value of b is: " "%d\n", b);
	return (0);
}
*/