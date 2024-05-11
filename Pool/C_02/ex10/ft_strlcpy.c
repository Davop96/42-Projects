/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:51:48 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/09 16:56:04 by dbohoyo-         ###   ########.fr       */
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
	char	dest[] = "Hasta luego";
	char	dest_strlcpy[] = "Hasta luego";
	unsigned int	size = 0;
	unsigned int	valor;

	valor = ft_strlcpy (dest, src, size);
	printf("Destino: ""%s y tamaño de origen %u\n", dest, valor);
	valor = strlcpy(dest_strlcpy, src, size);
	printf("Destino: ""%s y tamaño de origen %u\n", dest_strlcpy, valor);
}
 */