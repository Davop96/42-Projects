/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:03:25 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/10/02 10:19:30 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Auxiliary that initializes the identifier counters.
void	cb_init_identifiers(t_identifiers_count *c)
{
	c->so = 0;
	c->we = 0;
	c->ea = 0;
	c->no = 0;
	c->c = 0;
	c->f = 0;
}

// Auxiliary that compares all identifiers and adds their counters.
void	cb_compare_identifiers(char *line, t_identifiers_count *c)
{
	if (ft_strncmp(line, "SO ", 3) == 0)
		c->so++;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		c->we++;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		c->ea++;
	else if (ft_strncmp(line, "NO ", 3) == 0)
		c->no++;
	else if (ft_strncmp(line, "C ", 2) == 0)
		c->c++;
	else if (ft_strncmp(line, "F ", 2) == 0)
		c->f++;
}

// Validates that the identifiers SO, WE, EA, NO, C, F appear only once.
int	cb_check_identifiers_count(const char *filename)
{
	int					fd;
	char				*line;
	t_identifiers_count	c;

	cb_init_identifiers(&c);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: the .cub file could not be opened\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		cb_compare_identifiers(line, &c);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (c.so > 1 || c.we > 1 || c.ea > 1 || c.no > 1 || c.c > 1 || c.f > 1)
	{
		printf("Error: one color or texture of each type is allowed in .cub\n");
		return (1);
	}
	return (0);
}
