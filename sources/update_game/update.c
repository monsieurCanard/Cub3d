/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:09:41 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 20:06:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static get_side_wall(t_vector2 vector_ray, int hit_axis)
{
	if (hit_axis == 1)
	{
		if (vector_ray.x < 0)
			return (WE);
		else
			return (EA);
	}
	else
	{
		if (vector_ray.y < 0)
			return (NO);
		else
			return (SO);
	}
}

t_vector2	get_src_pixel(t_vector2 start, int line_height, t_vector2 *ray, int side, int size_y)
{
	t_vector2	src;

	src.y = roundf((start.y - (WIN_HEIGHT / 2) + line_height / 2) * size_y / line_height);
	if (side == NO)
		src.x = fabs(64 - (int)((ray->x - 32)) % 64 + start.x);
	else if (side == SO)
		src.x = fabs((int)(ray->x - 32) % 64 + start.x);
	else if (side == EA)
		src.x = fabs(64 + (int)(ray->y - 32) % 64 + start.x);
	else
		src.x = fabs((int)(ray->y - 32) % 64 + start.x);
	return (src);
}

static void	draw_3d_pov(t_data *data, t_ray *ray, int i)
{
	float		line_height;
	t_vector2	tex;
	t_vector2	start;
	int			side;
	float		scale;

	line_height = 32 * WIN_HEIGHT / ray->dist;
	start = vector2(i * WIN_WIDTH / FOV, (WIN_HEIGHT / 2) - line_height / 2);
	side = get_side_wall(ray->vector, ray->hit_axis);
	scale = data->texture[side]->size.x / 64;
	while (start.y < line_height + (WIN_HEIGHT / 2) - line_height / 2)
	{
		start.x = i * WIN_WIDTH / FOV;
		while (start.x < (i * WIN_WIDTH / FOV) + WIN_WIDTH / FOV)
		{
			tex = get_src_pixel(start, line_height, &ray->end, side, data->texture[side]->size.y);
			copy_pixel(get_engine()->win[1], data->texture[side], start, tex);
			start.x++;
		}
		start.y++;
	}
}

void	cast_60_ray(t_data *data)
{
	float		angle;
	int			i;
	float		fisheye_correc;
	t_ray		ray;

	i = 0;
	angle = data->player->obj->trans.rot.x - ((FOV / 2) * DR);
	while (i < FOV)
	{
		angle = cap_angle_rad(angle);
		ray.end = cast_ray(angle, data, &ray.hit_axis, i);
		ray.vector = sub_vector2(ray.end, data->player->obj->trans.pos);
		ray.dist = magnitude_vector2(ray.vector);
		fisheye_correc = cap_angle_rad(angle - data->player->obj->trans.rot.x);
		ray.dist *= cos(fabs(fisheye_correc));
		draw_3d_pov(data, &ray, i);
		angle += DR;
		i++;
	}
}

int	update(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	event_player_2d(data->player);
	draw_ceil_floor(data->map_data);
	cast_60_ray(data);
	return (0);
}
