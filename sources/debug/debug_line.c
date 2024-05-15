/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:10:05 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/15 16:02:12 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

static t_vector2	__cal_ray(float dist_h, float dist_v, t_vector2 end_h,
		t_vector2 end_v)
{
	t_vector2	ray;

	if (dist_h < dist_v)
		ray = end_h;
	else
		ray = end_v;
	return (ray);
}

t_vector2	update_raycast(void *obj, float angle)
{
	t_data		*data;
	t_vector2	end_h;
	t_vector2	end_v;
	t_vector2	ray_vector_h;
	t_vector2	ray_vector_v;

	data = (t_data *)obj;
	end_h = cast_ray_h(data->map_data, data->player->obj->trans.pos, angle);
	end_v = cast_ray_v(data->map_data, data->player->obj->trans.pos, angle);
	ray_vector_h = sub_vector2(end_h, data->player->obj->trans.pos);
	ray_vector_v = sub_vector2(end_v, data->player->obj->trans.pos);
	return (__cal_ray(magnitude_vector2(ray_vector_h),
			magnitude_vector2(ray_vector_v), end_h, end_v));
}

float	get_ray(t_data *data, float angle, int index)
{
	t_engine	*engine;
	t_vector2	raycast;

	engine = get_engine();
	engine->debug[index]->start = world_to_screen
		(data->player->obj->trans.pos, 0);
	raycast = update_raycast(data, angle);
	engine->debug[index]->end = world_to_screen(raycast, 0);
	engine->debug[index]->color = 0x00FF00;
	return (magnitude_vector2(sub_vector2(raycast,
				data->player->obj->trans.pos)));
}

// float	*draw_all_ray(void *obj)
// {
// 	int			i;
// 	float		angle;
// 	t_data		*data;
// 	float		*dist_ray;

// 	i = 0;
// 	data = (t_data *)obj;
// 	if (!dist_ray)
// 	{
// 		logerror(__FILE__, __LINE__, "malloc() failed");
// 		return (NULL);
// 	}
// 	return (dist_ray);
// }

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