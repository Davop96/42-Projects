/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:15:42 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/11 10:44:45 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	while (x < n && (s1[x] || s2[x]))
	{
		if (s1[x] != s2[x])
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return (0);
}

/* int	main(void)
{
	const char	*str1 = "Hola";
	const char	*str2 = "hola";
	int			result;

	result = ft_strncmp(str1, str2, 4);
	if (result < 0)
		printf("'%s' es menor que '%s'\n", str1, str2);
	else if (result > 0)
		printf("'%s' es mayor que '%s'\n", str1, str2);
	else
		printf("'%s' es igual que '%s'\n", str1, str2);

	return (0);
}
 */