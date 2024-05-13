/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:49:09 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:21:23 by dbohoyo-         ###   ########.fr       */
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
	char	chain[] = "HELLOWORLD";

	id = ft_str_is_uppercase(chain);
	printf("%d", id);
	return (0);
}
 */