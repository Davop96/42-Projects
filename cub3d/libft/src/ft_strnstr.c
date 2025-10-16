/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:02:51 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:42:05 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	x;
	size_t	y;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	x = 0;
	while (haystack[x] && x < len)
	{
		y = 0;
		while (haystack[x + y] == needle[y] && haystack[x + y] && x + y < len)
		{
			if (needle[y + 1] == '\0')
				return ((char *)&haystack[x]);
			y++;
		}
		x++;
	}
	return (NULL);
}
