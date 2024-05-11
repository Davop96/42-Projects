/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:20:15 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:23:10 by marvin           ###   ########.fr       */
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
	char	cadena[] = "HoLa MuNdO";

	str = ft_strlowcase(cadena);
	printf("%s", str);
	return (0);
}
*/