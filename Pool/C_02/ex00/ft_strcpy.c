/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:14:00 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:14:45 by marvin           ###   ########.fr       */
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
	char	src[] = "Hola mundo";
	char	dest[] = "";

	printf("Origen: ""%s\n", src);
	ft_strcpy (dest, src);
	printf("Destino: ""%s\n", dest);
}
 */