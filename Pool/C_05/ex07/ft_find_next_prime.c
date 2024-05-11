/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:46:00 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/05 16:48:45 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	x;

	x = 2;
	if (nb < 2)
	{
		return (2);
	}
	while (x <= nb / x)
	{
		if (nb % x == 0)
		{
			return (ft_find_next_prime(nb + 1));
		}
		else
		{
			x++;
		}
	}
	return (nb);
}

/* int	main(void)
{
	printf("%d\n", ft_find_next_prime(4));
	return (0);
}
 */