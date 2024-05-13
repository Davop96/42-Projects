/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:14:00 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 13:23:25 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	x;

	x = 0;
	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

/* int	main(void)
{
	char	src[] = "Hello world";
	char	dest[] = "";

	printf("Source: ""%s\n", src);
	ft_strcpy (dest, src);
	printf("Dest: ""%s\n", dest);
}
 */