/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:10:05 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/15 11:07:03 by antgabri         ###   ########.fr       */
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

static float	get_ray(t_data *data, float angle, int index)
{
	t_mrender	*renderer;
	t_vector2	raycast;

	renderer = get_renderer();
	renderer->debug[index]->start = world_to_screen2d
		(data->player->obj->trans.pos);
	raycast = update_raycast(data, angle);
	renderer->debug[index]->end = world_to_screen2d(raycast);
	renderer->debug[index]->color = 0x00FF00;
	return (magnitude_vector2(sub_vector2(raycast,
				data->player->obj->trans.pos)));
}

int	draw_all_ray(void *obj)
{
	int			i;
	float		angle;
	t_data		*data;
	float		*dist_ray;

	i = 0;
	data = (t_data *)obj;
	dist_ray = malloc(sizeof(float) * 60);
	if (!dist_ray)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (FAILURE);
	}
	angle = data->player->obj->trans.rot.x - ((FOV / 2) * DR);
	while (i < 60)
	{
		if (angle > 2 * PI)
			angle -= 2 * PI;
		else if (angle < 0)
			angle += 2 * PI;
		dist_ray[i] = get_ray(data, angle, i);
		angle += DR;
		i++;
	}
	return (SUCCESS);
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