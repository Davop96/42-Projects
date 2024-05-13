/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:27:41 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 13:23:50 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	x;

	x = 0;
	while (src[x] != '\0' && x < n)
	{
		dest[x] = src[x];
		x++;
	}
	while (x < n)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}

/*int	main(void)
{
	char	src[] = "Hello world";
	char	dest[] = "";
	unsigned int	n;

	n = 10;
	printf("Source: ""%s\n", src);
	ft_strncpy (dest, src, n);
	printf("Dest: ""%s\n", dest);
}
*/