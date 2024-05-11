/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:51:54 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/01 15:10:16 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str [count] != '\0')
	{
		count ++;
	}
	return (count);
}

/*int	main(void)
{
	char	str[] = "Hola amigo";

	printf("La longitud de esta palabra es de: ""%d", ft_strlen(str));
	return (0);
}
*/