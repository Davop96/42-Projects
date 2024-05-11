/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:48:58 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/10 10:50:59 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
#define GENERAL_H

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


void	ft_putstr(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return res;
}

char	*ft_strdup(char *src)
{
	int		x;
	int		len;
	char		*dest;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	x = 0;
	while (x < len)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

#endif