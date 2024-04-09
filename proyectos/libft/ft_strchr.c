/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:46:58 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/09 17:10:58 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/* int	main(void)
{
	const char	*str = "Hola Pepe";
	int			c;
	char		*result;

	c = 'o';
	result = ft_strchr(str, c);
	if (result)
		printf("'%c' found at position: %ld\n", c, result - str);
	else
		printf("'%c' not found\n", c);

	c = 'z';
	result = ft_strchr(str, c);
	if (result)
		printf("'%c' found at position: %ld\n", c, result - str);
	else
		printf("'%c' not found\n", c);
	return (0);
} */
