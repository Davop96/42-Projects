/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:51:31 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/10 16:47:30 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "general.h"

void	replacedotswithx(char *buffer, ssize_t length)
{
	ssize_t	x;

	x = 0;
	while (x < length)
	{
		if (buffer[x] == '.')
		{
			buffer[x] = 'x';
		}
		x++;
	}
}

int	main(int argc, char *argv[])
{
	int		map;
	int		number;
	char	buffer[1024];
	ssize_t	bytes_leidos;

	map = open("map.txt", O_RDONLY);
	bytes_leidos = read(map, buffer, sizeof(buffer));
	close(map);
	if (argc < 2)
	{
		write(1, "Error, you must write a number", 31);
		return (1);
	}
	number = atoi(argv[1]);
	if (number <= 0)
	{
		write(1, "Error, file can't be read", 26);
		return (1);
	}
	else
	{
		replacedotswithx(buffer, bytes_leidos);
		write(1, buffer, bytes_leidos);
		return (0);
	}
}
