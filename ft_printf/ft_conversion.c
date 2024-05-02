/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:38:14 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/30 14:43:26 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char	*format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*(format) == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (*format == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (*format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*format == 'p')
		count += ft_pointer(va_arg(args, void *));
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_pointer(void *ptr)
{
	int	count;

	count = 0;
	ft_putstr("0x");
	count += 2;
	count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
