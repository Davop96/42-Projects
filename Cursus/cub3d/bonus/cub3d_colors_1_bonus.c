/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_colors_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:45:00 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/10/02 11:46:46 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Extract the number from a string and convert it to int.
int	cb_parse_single_value(char *line, int *i)
{
	int	val;

	val = 0;
	while (line[*i] == ' ')
		(*i)++;
	if (!ft_isdigit(line[*i]))
		return (-1);
	while (ft_isdigit(line[*i]))
	{
		val = val * 10 + (line[*i] - '0');
		(*i)++;
	}
	while (line[*i] == ' ' || line[*i] == ',')
		(*i)++;
	if (line[*i] && !ft_isdigit(line[*i]) && line[*i] != '\0'
		&& line[*i] != '\n')
	{
		printf("Error: invalid character in RGB value.\n");
		return (-1);
	}
	return (val);
}

// Validates that RGB color values ​​are within the range [0, 255].
int	cb_validate_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		printf("Error: color out of range\n");
		return (1);
	}
	return (0);
}

// Check that the color line has exactly 3 RGB digits.
int	cb_validate_rgb_count(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 2;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			count++;
			while (ft_isdigit(line[i]))
				i++;
		}
		else
			i++;
	}
	if (count != 3)
	{
		printf("Error: RGB color must have exactly 3 values\n");
		return (1);
	}
	return (0);
}

// Parses and validates a line of text that defines an RGB color
// for the floor or ceiling, and stores it in the `cub` object.
int	cb_parse_color_line(char *line, t_cub3d *cub)
{
	int			i;
	int			r;
	int			g;
	int			b;
	char		type;

	i = 2;
	type = line[0];
	r = cb_parse_single_value(line, &i);
	if (line[i] == ',')
		i++;
	g = cb_parse_single_value(line, &i);
	if (line[i] == ',')
		i++;
	b = cb_parse_single_value(line, &i);
	if (cb_validate_rgb_count(line) || cb_validate_rgb(r, g, b))
		return (1);
	if (type == 'F')
		cub->floor_color = ((r << 24) | (g << 16) | (b << 8) | 0xFF);
	else if (type == 'C')
		cub->ceiling_color = ((r << 24) | (g << 16) | (b << 8) | 0xFF);
	return (0);
}
