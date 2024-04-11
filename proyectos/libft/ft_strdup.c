/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:02:30 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/11 12:33:55 by dbohoyo-         ###   ########.fr       */
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

/* int	main(void)
{
	const char	*str = "Hola, mundo!";
	char		*str_copy;

	str_copy = ft_strdup(str);
	if (str_copy == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	printf("Original string: %s\n", str);
	printf("Copied string: %s\n", str_copy);
	free(str_copy);
	return (0);
}
 */