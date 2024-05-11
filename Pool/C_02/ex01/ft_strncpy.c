/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:27:41 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:15:00 by marvin           ###   ########.fr       */
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
	char	src[] = "Hola mundo";
	char	dest[] = "";
	unsigned int	n;

	n = 10;
	printf("Origen: ""%s\n", src);
	ft_strncpy (dest, src, n);
	printf("Destino: ""%s\n", dest);
}
*/