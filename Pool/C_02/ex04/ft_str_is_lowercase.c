/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:35:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:21:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!(str[x] >= 'a' && str[x] <= 'z'))
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
	char	cadena[] = "holamundo";

	id = ft_str_is_lowercase(cadena);
	printf("%d", id);
	return (0);
}
 */