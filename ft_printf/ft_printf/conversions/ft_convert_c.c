/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:22:19 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/19 15:24:28 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(t_printf_data *data, va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (data->width > 1 && !data->flags.minus)
		ft_printf_pad(data, data->width - 1, ' ');
	ft_putchar_fd(c, 1);
	data->printed_chars++;
	if (data->width > 1 && data->flags.minus)
		ft_printf_pad(data, data->width - 1, ' ');
}
