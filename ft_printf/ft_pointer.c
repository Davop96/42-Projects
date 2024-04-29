/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:46:43 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/29 10:47:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *ptr)
{
	int	count;

	count = 0;
	ft_putstr("0x");
	count += 2;
	count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
