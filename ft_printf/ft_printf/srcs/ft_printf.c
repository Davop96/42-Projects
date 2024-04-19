/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:26:04 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/19 15:47:31 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	va_start(args, format);
	ft_initialize();
	ft_parse(format, args);
	count = ft_conversion(format, args);
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("Hello, world!\n");
	return (0);
}
