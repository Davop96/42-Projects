/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:10:39 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:46:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb <= 1 && nb >= 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		return (0);
	}
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}

/* int	main(void)
{
	int	nb;

	nb = 0;
	printf("The factorial of %d is: %d\n", nb, ft_recursive_factorial(nb));
	return (0);
}
 */