/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:21:31 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/11 11:36:48 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	val;

	res = 0;
	val = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			val = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * val);
}

/* int	main(void)
{
	const char	*str1 = "12345";
	const char	*str2 = "-6789";
	const char	*str3 = "  42";
	const char	*str4 = "    123abc";
	const char	*str5 = "abc123";

	printf("'%s' convertido a integer: %d\n", str1, ft_atoi(str1));
	printf("'%s' convertido a integer: %d\n", str2, ft_atoi(str2));
	printf("'%s' convertido a integer: %d\n", str3, ft_atoi(str3));
	printf("'%s' convertido a integer: %d\n", str4, ft_atoi(str4));
	printf("'%s' convertido a integer: %d\n", str5, ft_atoi(str5));

	return (0);
} */
