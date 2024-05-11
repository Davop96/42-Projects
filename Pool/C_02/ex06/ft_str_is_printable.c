/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:20:37 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:22:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!(str[x] >= ' ' && str[x] <= '~'))
		{
			return (0);
		}
		x++;
	}
	return (1);
}

/*int	main(void)
{
	int	id;
	char	cadena[] = "Hola mundo";

	id = ft_str_is_printable(cadena);
	printf("%d", id);
	return (0);
}
*/