/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:09:02 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:47:12 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	else if (power > 0)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	return (nb);
}

/* int	main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 4;
	printf("%d %d is: %d\n", nb, power, ft_recursive_power(nb, power));
	return (0);
}
 */