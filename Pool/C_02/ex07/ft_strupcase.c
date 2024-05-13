/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:28:25 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:22:01 by dbohoyo-         ###   ########.fr       */
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
	char	chain[] = "HeLlO WoRlD";

	str = ft_strupcase(chain);
	printf("%s", str);
	return (0);
}
*/