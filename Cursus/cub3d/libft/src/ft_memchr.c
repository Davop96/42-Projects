/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:44:23 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:40:03 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pt;
	unsigned char	ch;

	pt = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*pt == ch)
			return (pt);
		pt++;
	}
	return (NULL);
}
