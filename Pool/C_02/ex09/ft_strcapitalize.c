/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:26:43 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/06 11:09:33 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	x;

	if (str[0] >= 97 && str[0] <= 122)
		str[0] -= 32;
	x = 1;
	while (str[x] != '\0')
	{
		if (str[x] >= 65 && str[x] <= 90)
			str[x] += 32;
		if (str[x] >= 97 && str[x] <= 122)
		{
			if (!(str[x - 1] >= 97 && str[x - 1] <= 122))
			{
				if (!(str[x - 1] >= '0' && str[x - 1] <= '9'))
				{
					if (!(str[x - 1] >= 65 && str[x - 1] <= 90))
					{
						str[x] -= 32;
					}
				}
			}
		}
		x++;
	}
	return (str);
}

/* int	main(void)
{
	char	str[] = "salut, comMent tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(str));
	return (0);
}
 */