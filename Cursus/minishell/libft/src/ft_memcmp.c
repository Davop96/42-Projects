/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:15:37 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:43:26 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1x;
	unsigned char	*s2x;
	size_t			x;

	x = 0;
	s1x = (unsigned char *)s1;
	s2x = (unsigned char *) s2;
	while (x < n && *(s1x + x) == *(s2x + x))
		x++;
	if (x == n)
		return (0);
	return (*(s1x + x) - *(s2x + x));
}
