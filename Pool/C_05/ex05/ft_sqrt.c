/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:20:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:48:03 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	x;

	if (nb <= 0)
	{
		return (0);
	}
	if (nb == 1)
	{
		return (1);
	}
	x = 0;
	while ((nb / 2) >= x && x <= 46341)
	{
		if (x * x == nb)
		{
			return (x);
		}
		x++;
	}
	return (0);
}

/* int	main(void)
{
	int	nb;

	nb = 25;
	printf("%d is: %d\n", nb, ft_sqrt(nb));
	return (0);
}
 */