/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:21:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:34:05 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	x;

	x = 0;
	while (dest[x])
	{
		x++;
	}
	while (*src)
	{
		dest[x++] = *src++;
	}
	dest[x] = '\0';
	return (dest);
}

/* int	main(void)
{
	char	dest[] = "Hello world, see you";
	char	*src;

	src = " see you";
	printf("%s\n", ft_strcat(dest, src));
	return (0);
}
 */