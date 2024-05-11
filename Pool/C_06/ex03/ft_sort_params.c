/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:36:31 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/05 12:57:36 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
	{
		x++;
	}
	return (s1[x] - s2[x]);
}

int	main(int argc, char *argv[])
{
	char	*z;
	int		x;
	int		y;

	x = 0;
	while (argc > ++x)
	{
		y = x;
		while (argc > ++y)
		{
			if (ft_strcmp(argv[x], argv[y]) > 0)
			{
					z = argv[x];
					argv[x] = argv[y];
					argv[y] = z;
			}
		}
	}
	x = 0;
	while (++x < argc)
	{
		ft_putstr(argv[x]);
		write(1, "\n", 1);
	}
	return (0);
}
