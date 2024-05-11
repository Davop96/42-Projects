/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:23:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/11 10:35:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*res;
	int	x;

	x = 0;
	if (min >= max)
	{
		return (0);
	}
	res = malloc(sizeof(int) * (x));
	if (res == 0)
	{
		return (-1);
	}
	while (min < max)
	{
		res[x] = min;
		x++;
		min++;
	}
	*range = res;
	return (x);
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
	*tab = ft_ultimate_range(&tab, min, max);
	while (x < size)
	{
		printf("%d, ", tab[x]);
		x++;
	}
}
 */