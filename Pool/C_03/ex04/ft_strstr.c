/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:53:07 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:35:10 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	x;

	while (*str)
	{
		if (*str == *to_find)
		{
			x = 0;
			while (to_find[x] && str[x] == to_find[x])
			{
				x++;
			}
			if (to_find[x] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}

/* int	main(void)
{
	char	*str;
	char	*to_find;

	str = "is not healthy to sleep the entire day";
	to_find = "sleep";
	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
  */