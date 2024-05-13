/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:20:15 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:22:51 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	x;

	x = 0;
	while (*(str + x))
	{
		if (*(str + x) >= 65 && *(str + x) <= 90)
		{
			*(str + x) += 32;
		}
		x++;
	}
	return (str);
}

/*int	main(void)
{
	char	*str;
	char	chain[] = "HeLlO WoRlD";

	str = ft_strlowcase(chain);
	printf("%s", str);
	return (0);
}
*/