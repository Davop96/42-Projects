/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:44:23 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/11 11:03:14 by dbohoyo-         ###   ########.fr       */
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

/* int	main(void)
{
	const char	*str = "Hola, mundo!";
	int			c;
	void		*result;

	c = 'o';
	result = ft_memchr(str, c, 13);
	if (result)
		printf("'%c' encontrada en: %ld\n", c, (char *)result - (char *)str);
	else
		printf("'%c' no encontrada.\n", c);
	c = 'z';
	result = ft_memchr(str, c, 13);
	if (result)
		printf("'%c' encontrada en: %ld\n", c, (char *)result - (char *)str);
	else
		printf("'%c' no encontrada.\n", c);
}
 */