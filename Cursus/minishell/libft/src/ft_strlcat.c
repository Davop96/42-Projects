/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:21:06 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:43:49 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char*dst, const char*src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	x;
	size_t	y;

	x = 0;
	while (dst[x] && x < dstsize)
		x++;
	dst_len = x;
	y = 0;
	while (src[y])
		y++;
	src_len = y;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	y = 0;
	while (src[y] && dst_len + y < dstsize - 1)
	{
		dst[dst_len + y] = src[y];
		y++;
	}
	dst[dst_len + y] = '\0';
	return (dst_len + src_len);
}
