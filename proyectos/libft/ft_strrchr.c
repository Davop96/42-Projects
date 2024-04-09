/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:10:33 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/09 17:34:29 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last);
}

/* int	main(void)
{
	const char	*str = "Hola, Pepe";
	int			c;
	char		*result;

	c = 'o';
	result = ft_strrchr(str, c);
	if (result)
		printf("'%c' found at position: %ld\n", c, result - str);
	else
		printf("'%c' not found\n", c);

	c = 'z';
	result = ft_strrchr(str, c);
	if (result)
		printf("'%c' found at position: %ld\n", c, result - str);
	else
		printf("'%c' not found\n", c);
	return (0);
}
 */