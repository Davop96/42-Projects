/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:10:06 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 13:21:37 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *i, int *j)
{
	int	x;

	x = *i;
	*i = *j;
	*j = x;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = size -1;
	while (i < (size))
	{
		j = i + 1;
		x = i;
		while (j < size)
		{
			if (tab[j] < tab[x])
			{
				x = j;
			}
			j++;
		}
		ft_swap(&tab[i], &tab[x]);
		i++;
	}
}

/* int	main(void)
{
	int	size = 6;
	int	tab[] = {0, 3, 2, 6, 4, 9};
	int	i;

	i = 0;
	ft_sort_int_tab(tab, size);
	while (i <= size -1)
	{
		printf("The numbers sorted are: %d\n", tab[i]);
		i++;
	}
	return (0);
}
 */