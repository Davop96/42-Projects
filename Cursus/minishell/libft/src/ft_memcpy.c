/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:52:21 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:40:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (NULL);
	x = 0;
	d = (char *)dst;
	s = (char *)src;
	while (x < n)
	{
		d[x] = s[x];
		x++;
	}
	return (dst);
}
