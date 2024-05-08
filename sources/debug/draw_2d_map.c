/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/08 17:00:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <core_engine.h>

void	create_wall(int x, int y, size_t nb_obj)
{
	t_object2d	*obj;

	obj = new_obj2d("wall", nb_obj);
	obj->render = init_xmp_render2d("./debug/texture/full.xpm");
	obj->coord = new_coord(x, y);
}

void	create_floor(int x, int y, size_t nb_obj)
{
	t_object2d	*obj;

	obj = new_obj2d("floor", nb_obj);
	obj->render = init_xmp_render2d("./debug/texture/empty.xpm");
	obj->coord = new_coord(x, y);
}

void	create_player(int x, int y, size_t nb_obj)
{
	t_object2d	*obj;

	obj = new_obj2d("player", nb_obj);
	obj->render = init_xmp_render2d("./debug/texture/player_moche.xpm");
	// printf("obj->render.size.x = %f, obj->render.size.y = %f\n", obj->render.size.x, obj->render.size.y);
	obj->coord = new_coord(x, y);
}

void	create_debug_map(t_map *map)
{
	t_camera	*camera;
	size_t		nb_obj;
	int		x;
	int		y;

	y = 0;
	nb_obj = 0;
	while (y < (int)map->size_z)
	{
		x = 0;
		while (x < (int)map->size_x)
		{
			if (map->map[y][x] == '1')
			{
				create_wall(x * 25, -(y * 25), nb_obj);
				nb_obj++;
			}
			else if (map->map[y][x] == '0')
			{
				create_floor(x * 25, -(y * 25), nb_obj);
				nb_obj++;
			}
			else if (map->map[y][x] == 'N')
			{
				camera = new_camera();
				camera->coord.x = -(x * 25);
				camera->coord.y = y * 25;
				create_player(x * 25, -(y * 25), 499);
				nb_obj++;
			}
			x++;
		}
		y++;
	}
}
