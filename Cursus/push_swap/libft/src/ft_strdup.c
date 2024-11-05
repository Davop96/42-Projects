/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:02:30 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/10/29 15:24:12 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

char	*ft_strdup(const char *s1)
{
	size_t	count;
	char	*dest;

	count = ft_strlen(s1) + 1;
	dest = (char *)malloc(count);
	if (dest)
	{
		dest = (char *) ft_memcpy(dest, s1, count);
	}
	else
		return (NULL);
	return (dest);
}
