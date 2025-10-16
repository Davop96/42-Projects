/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_weapon_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:13:57 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/10/07 13:44:03 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	cb_mouse_hook(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_cub3d		*cub;
	double		now;

	cub = (t_cub3d *)param;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		if (cub->weapon.animating == 0)
		{
			now = cb_get_current_time();
			cub->weapon.anim_start_time = now;
			cub->weapon.animating = 1;
			cub->weapon.current_frame = 0;
		}
	}
}

static void	draw_weapon_pixel(t_cub3d *cub, t_weapon_draw_ctx *ctx,
	int x, int y)
{
	ctx->color = get_texture_pixel(ctx->tex, x, y);
	if ((ctx->color >> 24) != 0)
	{
		ctx->screen_x = (WIDTH - (int)ctx->tex->width) / 2 + ctx->offset + x;
		ctx->screen_y = HEIGHT - (int)ctx->tex->height + y;
		if (ctx->screen_x >= 0 && ctx->screen_x < WIDTH
			&& ctx->screen_y >= 0 && ctx->screen_y < HEIGHT)
			mlx_put_pixel(cub->game_img, ctx->screen_x,
				ctx->screen_y, ctx->color);
	}
}

static void	draw_weapon_texture(t_cub3d *cub, t_weapon_draw_ctx *ctx)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)ctx->tex->width)
	{
		y = 0;
		while (y < (int)ctx->tex->height)
		{
			draw_weapon_pixel(cub, ctx, x, y);
			y++;
		}
		x++;
	}
}

void	cb_draw_weapon(t_cub3d *cub)
{
	t_weapon_draw_ctx	ctx;

	ctx.tex = cub->weapon.frames[cub->weapon.current_frame];
	ctx.offset = WIDTH / 6;
	draw_weapon_texture(cub, &ctx);
}
