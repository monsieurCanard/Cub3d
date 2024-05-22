/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:10:05 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/22 18:37:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

static t_vector2	__cal_ray(float dist_h, float dist_v, t_vector2 end_h,
		t_vector2 end_v)
{
	t_vector2	ray;
	printf("dist_h: %f\n", dist_h);
	printf("dist_v: %f\n", dist_v);
	if (dist_h < dist_v)
	{
		ray = end_h;
	}
	else
	{
		ray = end_v;
	}
	return (ray);
}

static t_vector2	update_raycast(void *obj, float angle)
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

float	get_ray(t_data *data, float angle, int index, t_vector2 *coord_ray)
{
	t_engine	*engine;

	engine = get_engine();
	engine->debug[index]->start = world_to_screen
		(data->player->obj->trans.pos, 0);
	*coord_ray = update_raycast(data, angle);
	engine->debug[index]->end = world_to_screen(*coord_ray, 0);
	engine->debug[index]->color = 0x00FF00;
	return (magnitude_vector2(sub_vector2(*coord_ray,
				data->player->obj->trans.pos)));
}
