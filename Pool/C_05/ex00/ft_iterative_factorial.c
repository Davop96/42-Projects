/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:31:58 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:45:56 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	fact;

	fact = 1;
	if (nb < 0)
	{
		return (0);
	}
	while (nb >= 1)
	{
		fact *= nb;
		nb--;
	}
	return (fact);
}

/* int	main(void)
{
	int	nb;

	nb = 0;
	printf("The factorial of %d is: %d\n", nb, ft_iterative_factorial(nb));
	return (0);
}
 */