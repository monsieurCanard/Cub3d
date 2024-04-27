/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 23:02:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "cub3d.h"

void init_debug_img(void *engine, t_img **empty_img, t_img **full_img)
{
	*empty_img = init_xpm_img(engine, DEBUG_SQUARE_E, DEBUG_SIZE, DEBUG_SIZE);
	*full_img = init_xpm_img(engine, DEBUG_SQUARE_F, DEBUG_SIZE, DEBUG_SIZE);
}


void	draw_2d_map(void *engine, t_map *map)
{
	t_img	*empty_img;
	t_img	*full_img;
	size_t	x;
	size_t	y;
	
	init_debug_img(engine, &empty_img, &full_img);
	
	y = 0;
	while (y < map->size_z)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->map[y][x] == '1')
			{
				put_img_to_window(engine, full_img, (x - map->size_x / 2) * DEBUG_SIZE + (WIDTH / 2), (y - map->size_z/ 2) * DEBUG_SIZE + (HEIGHT / 2));
			}
			else if (map->map[y][x] == '0' || map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'E' || map->map[y][x] == 'W')
			{
				put_img_to_window(engine, empty_img, (x - map->size_x / 2) * DEBUG_SIZE + (WIDTH / 2), (y - map->size_z/ 2) * DEBUG_SIZE + (HEIGHT / 2));
			}
			x++;
		}
		y++;
	}
}
