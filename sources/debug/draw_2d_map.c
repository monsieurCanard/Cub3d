/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/09 16:23:07 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <core_engine.h>

void	create_wall(int x, int y, size_t nb_obj)
{
	t_object2d	*obj;

	obj = new_obj2d("wall", nb_obj);
	obj->render = init_xmp_render2d("./debug/texture/full_debug_square.xpm");
	obj->coord = new_coord(x, y);
	obj->scale = 0.64;
}

void	create_floor(int x, int y, size_t nb_obj)
{
	t_object2d	*obj;

	obj = new_obj2d("floor", nb_obj);
	obj->render = init_xmp_render2d("./debug/texture/empty_debug_square.xpm");
	obj->coord = new_coord(x, y);
	obj->scale = 0.64;
}

t_player	*create_player(int x, int y, size_t nb_obj)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	player->obj = new_obj2d("player", nb_obj);
	player->obj->angle = 3 * PI / 2;
	init_move_player(player);
	player->delta = new_coord(5 * cos(player->obj->angle),-(5 * sin(player->obj->angle)));
	player->obj->render = init_xmp_render2d("./debug/texture/player_octe.xpm");
	player->obj->coord = new_coord(x, y);
	player->obj->scale = 0.25;
	return (player);
}

void	create_debug_map(t_map *map, t_list **objs)
{
	t_camera	*camera;
	t_player	*player;
	size_t		nb_obj;
	int			x;
	int			y;

	y = 0;
	nb_obj = 0;
	while (y < (int)map->size_z)
	{
		x = 0;
		while (x < (int)map->size_x)
		{
			if (map->map[y][x] == '1')
			{
				create_wall(x * 64, -(y * 64), nb_obj);
				nb_obj++;
			}
			else if (map->map[y][x] == '0')
			{
				create_floor(x * 64, -(y * 64), nb_obj);
				nb_obj++;
			}
			else if (map->map[y][x] == 'N')
			{
				camera = new_camera();
				camera->coord.x = -(x * 64);
				camera->coord.y = y * 64;
				player = create_player(x * 64, -(y * 64), 499);
				ft_lstadd_back(objs, ft_lstnew(player));
				nb_obj++;
			}
			x++;
		}
		y++;
	}
	ft_lstadd_back(objs, ft_lstnew(map));
}
