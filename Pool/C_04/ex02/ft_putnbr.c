/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:23:04 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:30:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	x;

	if (nb < 0)
	{
		ft_putchar('-');
		x = -nb;
	}
	else
		x = nb;
	if (x > 9)
	{
		ft_putnbr(x / 10);
		x %= 10;
	}
	ft_putchar(x + '0');
}

/* int	main(void)
{
	ft_putnbr(-40000);
	return (0);
}
 */