/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_verifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 01:04:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/08/08 16:26:01 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_game *game)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (game->matrix[j][k] != '\n')
		k++;
	while (j < game->size.y)
	{
		i = 0;
		while (game->matrix[j][i] != '\n' && game->matrix[j][i] != '\0')
		{
			if (game->matrix[j][i] != '0' && game->matrix[j][i] != '1'
				&& game->matrix[j][i] != 'P' && game->matrix[j][i] != 'C'
				&& game->matrix[j][i] != 'E')
				return (1);
			i++;
		}
		if (k != i)
			return (1);
		j++;
	}
	return (0);
}

int	check_borders(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->matrix[j][i] != '\n' && game->matrix[j][i] != '\0')
		{
			if (j == 0 && game->matrix[j][i] != '1')
				return (1);
			if (j == game->size.y - 1 && game->matrix[j][i] != '1')
				return (1);
			if (j != 0 && (i == 0 || i == game->size.x - 1)
				&& game->matrix[j][i] != '1')
				return (1);
			if (j != game->size.y - 1 && (i == 0 || i == game->size.x - 1)
				&& game->matrix[j][i] != '1')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_objects(t_object	checked, t_object objects)
{
	if (checked.collec != objects.collec)
		return (1);
	if (checked.exit != objects.exit)
		return (1);
	if (checked.player != objects.player)
		return (1);
	return (0);
}

int	check_nbr_objects(t_object objects)
{
	if (objects.player != 1)
		return (1);
	if (objects.exit != 1)
		return (1);
	if (objects.collec < 1)
		return (1);
	return (0);
}

int	check_errors(t_game *game, t_object objects)
{
	int		flag;

	flag = -1;
	if (check_borders(game) == 1)
		flag = 1;
	if (check_rectangle(game) == 1)
		flag = 1;
	if (check_objects(game->object, objects) == 1)
		flag = 1;
	if (check_nbr_objects(objects) == 1)
		flag = 1;
	if (flag == 1)
	{
		(ft_printf("Error: Failed to load the map.\n"));
		return (1);
	}
	return (0);
}
