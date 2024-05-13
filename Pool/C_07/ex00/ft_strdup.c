/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:58:45 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:50:38 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		x;
	int		len;
	char	*dest;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
	{
		return (0);
	}
	x = 0;
	while (x < len)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

/* int	main(void)
{
	char	*str;
	char	*str2;

	str = "Hello world";
	str2 = ft_strdup(str);
	printf("%s\n", str2);
	return (0);
}
 */