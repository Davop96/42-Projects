/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:54 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/19 15:45:04 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <wchar.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
}				t_flags;

typedef struct s_width
{
	int			value;
	int			star;
}				t_width;

typedef struct s_precision
{
	int			value;
	int			star;
}				t_precision;

typedef struct s_length
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_length;

typedef struct s_specifier
{
	t_flags		flags;
	t_width		width;
	t_precision	precision;
	t_length	length;
	char		type;
}				t_specifier;

int			ft_conversion(const char *format, va_list args);
void		ft_initialize(void);
void		ft_parse(const char *format, va_list args);
void		ft_placeholder(const char *format, va_list args);
int			ft_printf(const char *format, ...);

#endif