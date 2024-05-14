/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/14 17:33:08 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_wall(int x, int y, size_t nb_obj)
{
	t_game_object	*obj;

	obj = new_object(nb_obj);
	init_xmp_render2d(obj, "./debug/texture/full_debug_square.xpm");
	obj->trans.pos = vector2(x, y);
	obj->type = WALL;
	obj->trans.scale.x = 0.64;
	obj->render.draw = &basic_draw2d;
}

void	create_floor(int x, int y, size_t nb_obj)
{
	t_game_object	*obj;

	obj = new_object(nb_obj);
	init_xmp_render2d(obj, "./debug/texture/empty_debug_square.xpm");
	obj->trans.pos = vector2(x, y);
	obj->type = FLOOR;
	obj->trans.scale.x = 0.64;
	obj->render.draw = &basic_draw2d;
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
	player->obj = new_object(nb_obj);
	player->obj->trans.rot.x = 3 * PI / 2;
	init_move_player(player);
	player->delta = vector2(5 * cos(player->obj->trans.rot.x),-(5 * sin(player->obj->trans.rot.x)));
	init_xmp_render2d(player->obj, "./debug/texture/player_octe.xpm");
	player->obj->trans.pos = vector2(x, y);
	player->obj->trans.scale.x = 0.25;
	player->obj->type = PLAYER;
	player->obj->render.draw = &basic_draw2d;
	return (player);
}

void	create_debug_map(t_data *data)
{
	t_camera	*camera;
	t_player	*player;
	size_t		nb_obj;
	int			x;
	int			y;

	y = 0;
	nb_obj = 0;
	while (y < (int)data->map_data->size_z)
	{
		x = 0;
		while (x < (int)data->map_data->size_x)
		{
			if (data->map_data->map[y][x] == '1')
			{
				create_wall(x * 64, -(y * 64), nb_obj);
				nb_obj++;
			}
			else if (data->map_data->map[y][x] == '0')
			{
				create_floor(x * 64, -(y * 64), nb_obj);
				nb_obj++;
			}
			else if (data->map_data->map[y][x] == 'N')
			{
				camera = new_camera();
				camera->coord.x = -(x * 64);
				camera->coord.y = y * 64;
				data->player = create_player(x * 64, -(y * 64), 999);
				create_floor(x * 64, -(y * 64), nb_obj++);
			}
			x++;
		}
		y++;
	}
}
