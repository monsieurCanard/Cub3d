/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:10:05 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/14 17:36:29 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

static bool	check_map(t_map *map, t_vector2 point, float angle)
{
	int	map_x;
	int	map_y;

	map_x = ((int)point.x + 32) / 64;
	if (angle < PI)
		map_y = -((int)point.y - 32) / 64;
	else if (angle > PI)
		map_y = -((int)point.y + 32) / 64;
	if (map_x >= 0 && map_y >= 0 && map_x < map->size_x && map_y < map->size_z && map->map[map_y][map_x] == '1')
		return (true);
	return (false);
}

t_vector2	next_intersection(t_map *map, t_vector2 point, float angle)
{
	t_vector2	intersection;
	int			dov;
	float		atan;

	atan = -1 / tan(angle);
	intersection = point;
	dov = 0;
	while (dov < 10)
	{
		if (check_map(map, intersection, angle) == true)
			break ;
		if (angle > PI)
		{
			intersection.x -= -64 * atan;
			intersection.y += 64;
		}
		else if (angle < PI)
		{
			intersection.x -= 64 * atan;
			intersection.y -= 64;
		}
		dov++;
	}
	return (intersection);
}

t_vector2	cast_ray_h(t_map *map, t_vector2 start, float angle)
{
	t_vector2	point;

	point = start;
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
	return (next_intersection(map, point, angle));
}

t_vector2	update_raycast(void *obj, float angle)
{
	t_data		*data;
	t_vector2	end_h;
	t_vector2	end_v;
	t_vector2	ray_vector_h;
	t_vector2	ray_vector_v;
	t_mrender	*renderer;
	t_vector2	raycast;

	data = (t_data *)obj;
	end_h = cast_ray_h(data->map_data, data->player->obj->trans.pos, angle);
	end_v = cast_ray_v(data->map_data, data->player->obj->trans.pos, angle);
	ray_vector_h = sub_vector2(end_h, data->player->obj->trans.pos);
	ray_vector_v = sub_vector2(end_v, data->player->obj->trans.pos);
	float dist_h = magnitude_vector2(ray_vector_h);
	float dist_v = magnitude_vector2(ray_vector_v);
	if (dist_h > dist_v)
		raycast = end_v;
	else
		raycast = end_h;
	return (raycast);
}

void draw_all_ray(void *obj)
{
	int i;
	float angle;
	t_data *data;

	data = (t_data *)obj;
	i = 0;
	angle = data->player->obj->trans.rot.x ;
	
}

// static bool	is_inside_square(t_vector2 point, t_vector2 start,
//		t_vector2 end)
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

// 	end_obj = (t_vector2){obj->trans.pos.x + (obj->render.size.x
//			* obj->trans.scale.x / 2),
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