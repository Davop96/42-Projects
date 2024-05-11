/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:28:06 by rimane-r          #+#    #+#             */
/*   Updated: 2023/09/24 19:29:46 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	condiciona(int i, int j, int column, int row)
{
	if (i == 1)
	{
		if (j == 1)
			ft_putchar('A');
		else if (j == row)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else if (i == column)
	{
		if (j == 1)
			ft_putchar('C');
		else if (j == row)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (j == 1 || j == row)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	rush(int row, int column)
{
	int	i;
	int	j;

	i = 1;
	if (row <= 0 || column <= 0)
	{
		write(1, "Por favor introduzca un dígito válido", 40);
	}
	else
	{
		while (i <= column)
		{
			j = 1;
			while (j <= row)
			{
				condiciona(i, j, column, row);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}
