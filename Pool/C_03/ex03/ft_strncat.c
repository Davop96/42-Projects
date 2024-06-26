/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:16:48 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:34:35 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (dest[x] != '\0')
	{
		x++;
	}
	while (src[y] != '\0' && y < nb)
	{
		dest[x++] = src[y++];
	}
	dest[x] = '\0';
	return (dest);
}

/*int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Error: You must write at least two words and a number");
		return (-1);
	}
	else
	{
		printf("%s", ft_strncat(argv[1], argv[2], *argv[3]));
		return (0);
	}
}
*/