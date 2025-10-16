/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:30:40 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:41:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;

	x = 0;
	while (*src && x + 1 < dstsize)
	{
		*dst++ = *src++;
		x++;
	}
	if (x < dstsize)
		*dst = 0;
	while (*src++)
		x++;
	return (x);
}
