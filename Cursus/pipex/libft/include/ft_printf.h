/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:29:28 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/09/23 14:17:00 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_format
{
	va_list		ap;
}			t_format;

int			ft_printf(const char *format, ...);
int			ft_format(const char *format, va_list args);
char		*ft_strchr(const char *s, int c);
int			ft_conversion(const char	*format, va_list args);
int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_putnbr_base(unsigned long nbr, char *base);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_pointer(void *ptr);

#endif