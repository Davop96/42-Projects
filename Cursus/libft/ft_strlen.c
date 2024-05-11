/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:36:18 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/09 11:01:39 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *c)
{
	int	x;

	x = 0;
	while (c[x] != '\0')
		x++;
	return (x);
}

/* int	main(void)
{
	const char *c = "hola"
	printf("%d\n", ft_strlen(c));
	return (0);
} */