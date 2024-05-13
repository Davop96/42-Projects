/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:35:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:20:12 by dbohoyo-         ###   ########.fr       */
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
	char	chain[] = "helloworld";

	id = ft_str_is_lowercase(chain);
	printf("%d", id);
	return (0);
}
 */