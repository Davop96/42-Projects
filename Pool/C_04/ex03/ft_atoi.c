/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:12:33 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:45:10 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	x;
	int	sign;
	int	res;

	x = 0;
	sign = 0;
	res = 0;
	while (spaces(str[x]))
		x++;
	while ((str[x] == '+' || str[x] == '-'))
	{
		if (str[x] == '-')
			sign++;
		x++;
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		res = res * 10 + (str[x] - 48);
		x++;
	}
	if (sign % 2 == 1)
		return (res * -1);
	return (res);
}

/* int	main(void)
{
	char	*str;

	str = "\n---+--+1234ab567";
	printf("%d\n", ft_atoi(str));
	return (0);
}
 */