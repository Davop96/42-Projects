/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:49:09 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:21:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!(str[x] >= 'A' && str[x] <= 'Z'))
		{
			return (0);
		}
		x++;
	}
	return (1);
}

/* int	main(void)
{
	int	id;
	char	cadena[] = "HOLAMUNDO";

	id = ft_str_is_uppercase(cadena);
	printf("%d", id);
	return (0);
}
 */