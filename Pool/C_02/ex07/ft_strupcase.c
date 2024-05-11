/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:28:25 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:22:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	x;

	x = 0;
	while (*(str + x))
	{
		if (*(str + x) >= 97 && *(str + x) <= 122)
		{
			*(str + x) -= 32;
		}
		x++;
	}
	return (str);
}

/*int	main(void)
{
	char	*str;
	char	cadena[] = "HoLa MuNdO";

	str = ft_strupcase(cadena);
	printf("%s", str);
	return (0);
}
*/