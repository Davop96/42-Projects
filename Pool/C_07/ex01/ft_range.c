/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:47:55 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/11 10:35:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	x;
	int	*res;

	if (min >= max)
	{
		return (0);
	}
	x = max - min;
	res = (int *)malloc(sizeof(int) * x);
	if (res == 0)
	{
		return (0);
	}
	x = 0;
	while (max > min)
	{
		res[x] = min;
		min++;
		x++;
	}
	return (res);
}

/* int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	x;
	int	size;

	min = 5;
	max = 10;
	x = 0;
	size = max - min;
	tab = ft_range(min, max);
	while (x < size)
	{
		printf("%d, ", tab[x]);
		x++;
	}
}
 */