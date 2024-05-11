/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:18:44 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/03 15:44:50 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	x;
	int	y;

	x = 1;
	y = nb;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	while (x < power)
	{
		y = y * nb;
		x++;
	}
	return (y);
}

/* int	main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 5;
	printf("%d elevado a %d es: %d\n", nb, power, ft_iterative_power(nb, power));
	return (0);
}
 */