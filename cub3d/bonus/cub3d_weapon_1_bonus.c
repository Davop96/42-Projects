/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_weapon_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:09:02 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/09/26 11:12:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cb_init_weapon(t_weapon *weapon)
{
	int	i;

	weapon->frames = malloc(sizeof(mlx_texture_t *) * NUM_WEAPON_FRAMES);
	if (!weapon->frames)
	{
		printf("Error: malloc failed for weapon frames\n");
		exit(1);
	}
	i = 0;
	while (i < NUM_WEAPON_FRAMES)
	{
		weapon->frames[i] = NULL;
		i++;
	}
	weapon->num_frames = NUM_WEAPON_FRAMES;
	weapon->current_frame = 0;
	weapon->animating = 0;
	weapon->anim_start_time = 0.0;
}

int	cb_load_weapon_frames(t_weapon *weapon)
{
	char	*paths[NUM_WEAPON_FRAMES];
	int		i;

	paths[0] = "textures/weapon1.png";
	paths[1] = "textures/weapon2.png";
	paths[2] = "textures/weapon3.png";
	paths[3] = "textures/weapon4.png";
	i = 0;
	while (i < NUM_WEAPON_FRAMES)
	{
		weapon->frames[i] = mlx_load_png(paths[i]);
		if (!weapon->frames[i])
		{
			printf("Error: Failed to load weapon frame %d '%s'.\n",
				i, paths[i]);
			cb_free_weapon(weapon);
			return (1);
		}
		i++;
	}
	return (0);
}

void	cb_free_weapon(t_weapon *weapon)
{
	int	i;

	if (weapon->frames)
	{
		i = 0;
		while (i < weapon->num_frames)
		{
			if (weapon->frames[i])
				mlx_delete_texture(weapon->frames[i]);
			i++;
		}
		free(weapon->frames);
		weapon->frames = NULL;
	}
}

double	cb_get_current_time(void)
{
	struct timeval	tv;
	double			time_in_sec;

	if (gettimeofday(&tv, NULL) != 0)
	{
		perror("gettimeofday failed");
		exit(EXIT_FAILURE);
	}
	time_in_sec = (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
	return (time_in_sec);
}

void	cb_update_weapon_animation(t_cub3d *cub)
{
	double		now;
	double		elapsed;
	int			frame;

	if (cub->weapon.animating == 0)
		return ;
	now = cb_get_current_time();
	elapsed = (now - cub->weapon.anim_start_time) * 1000.0;
	frame = (int)(elapsed / WEAPON_FRAME_DURATION_MS);
	if (frame >= cub->weapon.num_frames)
	{
		cub->weapon.animating = 0;
		cub->weapon.current_frame = 0;
	}
	else
		cub->weapon.current_frame = frame;
}
