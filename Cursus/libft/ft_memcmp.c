/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:15:37 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/09 12:53:04 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1x;
	unsigned char	*s2x;
	size_t			x;

	x = 0;
	s1x = (unsigned char *)s1;
	s2x = (unsigned char *) s2;
	while (x < n && *(s1x + x) == *(s2x + x))
		x++;
	if (x == n)
		return (0);
	return (*(s1x + x) - *(s2x + x));
}

/* int	main(void)
{
	char	str1[20] = "Holaaa";
	char	str2[20] = "Holaaa";
	int		res;

	res = ft_memcmp(str1, str2, 5);
	if (res > 0)
	{
		printf("str2 es menor que str1.\n");
	}
	else if (res < 0)
	{
		printf("str1 es menor que str2.\n");
	}
	else
	{
		printf("str1 es igual a str2.\n");
	}
	return (0);
} */
