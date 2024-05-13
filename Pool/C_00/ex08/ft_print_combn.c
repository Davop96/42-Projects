/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:26 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 13:14:14 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	combina(int n, int *tab, int pos)
{
	int	i;

	if (pos == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	incrementa(int n, int *tab)
{
	int	i;
	int	mas;

	i = n -1;
	mas = 9;
	while (tab[i] == mas)
	{
		i -= 1;
		mas -= 1;
	}
	tab [i] += 1;
	while (i < n)
	{
		tab[i + 1] = tab[i] + 1;
		i += 1;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	i = 0;
	while (i < n)
	{
		tab [i] = i;
		i++;
	}
	combina(n, tab, 0);
	while (tab[0] != 10 - n || tab[n - 1] != 9)
	{
		if (tab [n - 1] != 9)
		{
			tab[n -1] += 1;
		}
		else
		{
			incrementa(n, tab);
		}
		combina(n, tab, 1);
	}
}

/* int	main(void)
{
	int	n;

	n = 2;
	ft_print_combn(n);
	return (0);
}
 */