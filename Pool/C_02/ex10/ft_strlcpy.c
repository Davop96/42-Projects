/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:51:48 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:29:43 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str != '\0')
	{
		count ++;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	x;

	x = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[x] != '\0' && x < size - 1)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (ft_strlen(src));
}

/* int	main(void)
{
	char	src[] = "";
	char	dest[] = "See you";
	char	dest_strlcpy[] = "See you";
	unsigned int	size = 0;
	unsigned int	value;

	valor = ft_strlcpy (dest, src, size);
	printf("Dest: ""%s %u\n", dest, value);
	value = strlcpy(dest_strlcpy, src, size);
	printf("Dest: ""%s %u\n", dest_strlcpy, value);
}
 */