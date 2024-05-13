/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:10:05 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/13 17:43:41 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector2	next_intersection(t_map *map, t_vector2 point, float angle)
{
	t_vector2	intersection;
	int			map_x;
	int			map_y;
	int			dov;
	float		atan;

	atan = -1 / tan(angle);
	intersection = point;
	dov = 0;
	while (dov < 10)
	{
		if (angle > PI)
		{
			intersection.x += -(-64 * atan);
			intersection.y += 64;
		}
		else if (angle < PI)
		{
			intersection.x += - (64 * atan);
			intersection.y += -64;
		}
		map_x = ((int)intersection.x + 32) / 64;
		map_y = -((int)intersection.y + 96) / 64;
		printf("map_x = %d, map_y = %d\n", map_x, map_y);
		if (map_x > 0 && map_y > 0 && map[map_y][map_x] == '1')
			break ;
		dov++;
	}
	return (intersection);
}

t_vector2	cast_ray_h(char **map ,t_vector2 start, float angle)
{
	t_vector2	point;
	t_vector2	raiser;
	float		step;

	if (angle < PI)
	{
		point.y = ((((int)start.y + 32) >> 6) << 6) - 32;
		point.x = (start.y - point.y) / tan(angle) + start.x;
	}
	else if (angle > PI)
	{
		point.y = ((((int)start.y + 32) >> 6) << 6) + 32;
		point.x = (start.y - point.y) / tan(angle) + start.x;
	}
	else
		return (start);
	return (next_intersection(map, point, angle));
}

int	update_raycast(void *obj)
{
	t_data			*data;
	t_vector2		end;
	t_mrender		*renderer;

	data = (t_data *)obj;
	end = cast_ray_h(data->map_data->map, data->player->obj->trans.pos, data->player->obj->trans.rot.x);
	renderer = get_renderer();
	
	renderer->debug[0]->start = world_to_screen2d(data->player->obj->trans.pos);
	renderer->debug[0]->end = world_to_screen2d(end);
	renderer->debug[0]->color = 0x00FF00;
	return (SUCCESS);
}


// static bool	is_inside_square(t_vector2 point, t_vector2 start, t_vector2 end)
// {
// 	if (point.x >= start.x && point.x <= end.x
// 		&& point.y <= start.y && point.y >= end.y)
// 	{
// 		return (true);
// 	}
// 	return (false);
// }

// static t_vector2	__cal_start_obj(t_game_object *obj)
// {
// 	t_vector2	start_obj;
// 	t_engine	*engine;
// 	float		scale;

// 	scale = obj->trans.scale.x;
// 	engine = get_engine();
// 	start_obj = (t_vector2){obj->trans.pos.x - (obj->render.size.x * scale / 2),
// 		obj->trans.pos.y + (obj->render.size.y * scale / 2),};
// 	return (start_obj);
// }

// static t_vector2	__cal_end_obj(t_game_object *obj)
// {
// 	t_vector2	end_obj;

// 	end_obj = (t_vector2){obj->trans.pos.x + (obj->render.size.x * obj->trans.scale.x / 2),
// 		obj->trans.pos.y - (obj->render.size.y * obj->trans.scale.x / 2),};
// 	return (end_obj);
// }

// static bool	verif_point(t_vector2 point, int j)
// {
// 	t_engine	*engine;
// 	t_vector2	start_obj;
// 	t_vector2	end_obj;

// 	engine = get_engine();
// 	start_obj = __cal_start_obj(engine->obj2d[j]);
// 	end_obj = __cal_end_obj(engine->obj2d[j]);
// 	if (is_inside_square(point, start_obj, end_obj) == true
// 		&& engine->obj2d[j]->type == 1)
// 	{
// 		return (true);
// 	}
// 	return (false);
// }

// t_vector2	cast_ray(t_vector2 start, float angle)
// {
// 	t_vector2	point;
// 	t_vector2	raiser;
// 	float		step;

// 	raiser.x = cos(angle);
// 	raiser.y = sin(angle);
// 	step = 0.1;
// 	while (step < 70)
// 	{
// 		point = (t_vector2){start.x + step * raiser.x,
// 			start.y - step * raiser.y};
// 		if (((int)roundf(point.x - 32) % 64 == 0
// 				|| (int)roundf(point.y - 32) % 64 == 0))
// 		{
// 			return (next_intersection(point, angle));
// 		}
// 		step += 0.1;
// 	}
// 	return (point);
// }