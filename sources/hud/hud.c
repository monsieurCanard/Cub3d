/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:54:21 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/30 17:40:26 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hud.h"

void	update_minimap(t_texture *minimap, t_player *player)
{
	t_vector2	dst;
	t_vector2	size;
	t_vector2	iter;
	int			color;

	(void)player;
	dst = vector2(50, 50);
	size = vector2(100, 100);
	iter = vector2(0, 0);
	while (iter.y < size.y)
	{
		iter.x = 0;
		while (iter.x < size.x)
		{
			color = take_pixel(minimap,
					vector2(
						(iter.x + (player->pos.y * 10) + (size.x / 2)),
						(iter.y + (player->pos.x * 10) - (size.y / 2)))
					);
			pixel_put(__get_engine()->win[0], vector2(dst.x + iter.x, dst.y + iter.y), color);
			iter.x++;
		}
		iter.y++;
	}
}

void	update_hud(t_data *data)
{
	update_minimap(data->minimap, data->player);
}
