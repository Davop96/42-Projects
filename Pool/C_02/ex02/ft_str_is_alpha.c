/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:57:03 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:19:21 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!((str[x] >= 'A' && str[x] <= 'Z') || (str[x] >= 'a'
					&& str[x] <= 'z')))
		{
			return (0);
			break ;
		}
		x++;
	}
	return (1);
}

/* int	main(void)
{
	int	id;
	char	chain[] = "Helloworld";

	id = ft_str_is_alpha(chain);
	printf("%d", id);
	return (0);
}
 */