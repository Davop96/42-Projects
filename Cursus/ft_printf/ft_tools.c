/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:08:51 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/29 16:02:31 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		len += 6;
	}
	else
	{
		while (*s)
		{
			ft_putchar(*s++);
			len++;
		}
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (count + 1);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	base_len;
	int	count;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= (unsigned long)base_len)
	{
		count += ft_putnbr_base(nbr / base_len, base);
	}
	ft_putchar(base[nbr % base_len]);
	count++;
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_unsigned(n / 10);
		count += ft_putnbr_unsigned(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		count++;
	}
	return (count);
}
