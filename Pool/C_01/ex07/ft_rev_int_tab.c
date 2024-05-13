/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:14:12 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 13:20:58 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = size -1;
	while (i < (size / 2))
	{
		x = tab[i];
		tab[i] = tab[j];
		tab[j] = x;
		i++;
		j--;
	}
}

/* int	main(void)
{
	int	size = 6;
	int	tab[] = {0, 1, 2, 3, 4, 5};
	int	i;

	i = 0;
	ft_rev_int_tab(tab, size);
	while (i <= size -1)
	{
		printf("Now the numbers are: %d\n", tab[i]);
		i++;
	}
	return (0);
}
 */