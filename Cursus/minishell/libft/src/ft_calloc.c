/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:36:30 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/03/03 16:35:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*pt;
	size_t	total_size;
	size_t	x;

	total_size = count * size;
	pt = malloc(total_size);
	if (pt == NULL)
		return (NULL);
	x = 0;
	while (x < total_size)
	{
		((char *)pt)[x] = 0;
		x++;
	}
	return (pt);
}
