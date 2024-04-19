/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:02:21 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/09 14:31:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	x;
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	x = 0;
	if (d == s)
		return (d);
	if (s < d)
	{
		x = len;
		while (x--)
			((char *)d)[x] = ((char *)s)[x];
	}
	else
	{
		x = 0;
		while (x < len)
		{
			((char *)d)[x] = ((char *)s)[x];
			x++;
		}
	}
	return (dst);
}

/* int	main(void)
{
	char dst[100] = "Vivan las manzanas";
	char src[100] = "Vivan las peras.";

	ft_memmove(dst, src, 5);
	printf("dst cambiado con el src: %s\n", dst);
	return (0);
} */
