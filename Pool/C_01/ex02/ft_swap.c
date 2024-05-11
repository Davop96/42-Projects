/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:24:43 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/09/25 10:29:16 by dbohoyo-         ###   ########.fr       */
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
	printf("El valor de a es: " "%d\n", a);
	printf("El valor de b es: " "%d\n", b);
	return (0);
}
*/