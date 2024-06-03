/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:47:03 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 15:10:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"

t_vector2	rotate_point(t_vector2 point, float angle)
{
	t_vector2	result;

	result.x = point.x * cos(angle) - point.y * sin(angle);
	result.y = point.x * sin(angle) + point.y * cos(angle);
	return (result);
}

static bool	is_player(t_vector2 dst)
{
	float	dst_player_sqr;

	dst_player_sqr = (dst.x - SIZE_MINIMAP / 2) * (dst.x - SIZE_MINIMAP / 2)
		+ (dst.y - SIZE_MINIMAP / 2) * (dst.y - SIZE_MINIMAP / 2);
	if (dst_player_sqr <= RAD_SQR_PLAYER)
	{
		return (true);
	}
	return (false);
}

int	take_minimap_color(t_vector2 src, t_texture *minimap,
	t_vector2 dst, float dist_sqr)
{
	float	rad;
	float	angle;
	int		color;

	rad = SIZE_MINIMAP / 2;
	if (dist_sqr >= (rad - BORDER_SIZE_MP) * (rad - BORDER_SIZE_MP))
	{
		return (0x75B9A2);
	}
	else if (src.x < 0 || src.x >= minimap->size.x
		|| src.y < 0 || src.y >= minimap->size.y)
	{
		return (0x06170E);
	}
	else if (is_player(dst) == true)
		return (0x75B9A2);
	else
	{
		angle = atan2f((dst.y - rad), (dst.x - rad)) + PI / 2;
		angle = cap_angle(angle);
		color = take_pixel(minimap, src);
		if (!(fabs(angle) <= 0.65))
			return (apply_shade(color, 0.7));
		return (color);
	}
}

static void	draw_pixel_minimap(t_vector2 iter, t_texture *minimap,
	t_player *player, float angle)
{
	t_vector2	src;
	float		dist_sqr;
	float		radius;

	radius = SIZE_MINIMAP / 2;
	dist_sqr = (iter.x - radius) * (iter.x - radius)
		+ (iter.y - radius) * (iter.y - radius);
	if (dist_sqr <= radius * radius)
	{
		src = rotate_point(vector2(iter.x - radius,
					iter.y - radius), angle);
		src.x += (player->pos.y * SIZE_SQUARE);
		src.y += (player->pos.x * SIZE_SQUARE);
		pixel_put(__get_engine()->win[0],
			vector2(OFFSET_MINIMAP + iter.x, OFFSET_MINIMAP + iter.y),
			take_minimap_color(src, minimap, iter, dist_sqr));
	}
}

void	update_minimap(t_texture *minimap, t_player *player)
{
	t_vector2	iter;
	float		angle;

	iter = vector2(0, 0);
	angle = -atan2f(player->dir.y, -player->dir.x);
	while (iter.y < SIZE_MINIMAP)
	{
		iter.x = 0;
		while (iter.x < SIZE_MINIMAP)
		{
			draw_pixel_minimap(iter, minimap, player, angle);
			iter.x++;
		}
		iter.y++;
	}
}
