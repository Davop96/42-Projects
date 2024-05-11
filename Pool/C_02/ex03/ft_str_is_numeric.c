/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:59:27 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/16 13:16:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	x;
	int	id;

	x = 0;
	id = 1;
	while (str[x] != '\0')
	{
		if (!(str[x] >= '0' && str[x] <= '9'))
		{
			id = 0;
			break ;
		}
		x++;
	}	
	return (id);
}

/* int	main(void)
{
	char	*str = "777";
	int	cadena;

	cadena = ft_str_is_numeric(str);
	printf("%i", cadena);
	return (0);
}
 */