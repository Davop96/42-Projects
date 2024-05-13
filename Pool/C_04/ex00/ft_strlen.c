/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:51:54 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:43:52 by dbohoyo-         ###   ########.fr       */
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
	char	str[] = "Hello friend";

	printf("The lenght of this string is: ""%d", ft_strlen(str));
	return (0);
}
*/