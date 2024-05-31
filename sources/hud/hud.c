/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:54:21 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/31 14:30:01 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hud.h"

t_vector2	rotate_point(t_vector2 point, float angle)
{
	t_vector2	result;

	result.x = point.x * cos(angle) + point.y * sin(angle);
	result.y = point.x * sin(angle) - point.y * cos(angle);
	return (result);
}

void	update_minimap(t_texture *minimap, t_player *player)
{
	t_vector2	dst_offset;
	t_vector2	size;
	t_vector2	iter;
	t_vector2	dst;
	int			color;

	dst_offset = vector2(50, 50);
	size = vector2(100, 100);
	iter = vector2(0, 0);
	float angle = atan2f(player->dir.y, -player->dir.x);
	while (iter.y < size.y)
	{
		iter.x = 0;
		while (iter.x < size.x)
		{
			t_vector2 tmp = rotate_point(vector2(iter.x - size.x / 2, iter.y - size.y / 2), angle);		

			tmp.x += (player->pos.y * 10);
			tmp.y += (player->pos.x * -10) + size.y / 2;
			
			if (tmp.x < 0 || tmp.x >= minimap->size.x
				|| tmp.y < 0 || tmp.y >= minimap->size.y)
				color = 0x000000;
			else
				color = take_pixel(minimap, tmp);
			if (iter.x >= size.x / 2 - 3 && iter.y >= size.y / 2 - 3 && iter.x <= size.x / 2 + 3 && iter.y <= size.y / 2 + 3)
				color = 0x00FFFF;
			dst = vector2(dst_offset.x + iter.x, dst_offset.y + iter.y);
			pixel_put(__get_engine()->win[0], dst, color);
			iter.x++;
		}
		iter.y++;
	}
}

void	update_hud(t_data *data)
{
	update_minimap(data->minimap, data->player);
}
