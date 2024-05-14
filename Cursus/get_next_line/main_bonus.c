/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:07:57 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/14 17:17:25 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_and_print_lines(int fd1, int fd2, int fd3)
{
	char	*line;
	int		i ;

	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test/file1.txt", O_RDONLY);
	fd2 = open("test/file2.txt", O_RDONLY);
	fd3 = open("test/file3.txt", O_RDONLY);
	read_and_print_lines(fd1, fd2, fd3);
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
