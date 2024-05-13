/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:33:14 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:31:23 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x])
	{
		if (s1[x] != s2[x])
		{
			return (s1[x] - s2[x]);
		}
		x++;
	}
	return (s1[x] - s2[x]);
}

/*int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error: You must write at least two words");
		return (-1);
	}
	else
	{
		printf("%d", ft_strcmp(argv[1], argv[2]));
		return (0);
	}
}
*/