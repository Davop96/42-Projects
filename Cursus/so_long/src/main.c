/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:29:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/06/14 03:00:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char	*path)
{
	char	*str;
	int		len;
	int		i;

	str = ".ber";
	len = ft_strlen(path);
	if (len == 11)
		return (1);
	len = len - 4;
	i = 0;
	while (str[i])
	{
		if (path[len + i] != str[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		ft_printf("Error: Invalid number of arguments");
	if (argc == 2)
	{
		if (check_file(argv[1]) == 1)
		{
			ft_printf("Error: Invalid map format\n");
			return (1);
		}
		i = initializes_map(argv[1]);
		if (i == 1)
			return (1);
	}
	return (0);
}
