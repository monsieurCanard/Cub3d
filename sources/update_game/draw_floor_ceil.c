/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceil.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:46 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 18:02:48 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_part(int color, t_vector2 start, t_vector2 end)
{
	t_vector2	iterator;

	iterator = start;
	while (iterator.y < end.y)
	{
		iterator.x = start.x;
		while (iterator.x < 1080)
		{
			pixel_put(__get_engine()->win[0], iterator, color);
			iterator.x++;
		}
		iterator.y++;
	}
}

void	draw_ceil_floor(t_map *map_data)
{
	t_vector2	start;
	int			color;

	start = vector2(0, 0);
	color = create_trgb(map_data->ceiling.a, map_data->ceiling.r,
			map_data->ceiling.g, map_data->ceiling.b);
	draw_part(color, start, vector2(WIN_WIDTH, WIN_HEIGHT / 2));
	start = vector2(0, WIN_HEIGHT / 2);
	color = create_trgb(map_data->floor.a, map_data->floor.r,
			map_data->floor.g, map_data->floor.b);
	draw_part(color, start, vector2(WIN_WIDTH, WIN_HEIGHT));
}
