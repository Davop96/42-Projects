/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:02:30 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:41:14 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	x;

	len = 0;
	while (s1[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	x = 0;
	while (x < len)
	{
		dup[x] = s1[x];
		x++;
	}
	dup [x] = '\0';
	return (dup);
}
