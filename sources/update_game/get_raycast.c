/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:57 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/22 19:23:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_side_wall(t_vector2 *ray, t_player *player)
{
	t_vector2	vector;
	static int	old_side;

	vector = sub_vector2(*ray, player->obj->trans.pos);
	if ((int)(ray->y - 32) % 64 == 0 && (int)(ray->x - 32) % 64 != 0)
	{
		if (vector.y < 0)
			old_side = NO;
		else
			old_side = SO;
	}
	else if ((int)(ray->x - 32) % 64 == 0 && (int)(ray->y - 32) % 64 != 0)
	{
		if (vector.x < 0)
			old_side = EA;
		else
			old_side = WE;
	}
	return (old_side);
}

t_vector2	get_src_pixel(t_vector2 start, int line_height, t_vector2 *ray, int side, int size_y)
{
	t_vector2	src;

	src.y = roundf((start.y - 540 + line_height / 2) * size_y / line_height);
	if (side == NO)
		src.x = abs(64 - (int)((ray->x - 32)) % 64 + start.x);
	else if (side == SO)
		src.x = abs((int)(ray->x - 32) % 64 + start.x);
	else if (side == EA)
		src.x = abs(64 + (int)(ray->y - 32) % 64 + start.x);
	else
		src.x = abs((int)(ray->y - 32) % 64 + start.x);
	return (src);
}

static void	draw_3d_pov(float dist_ray, t_data *data,
	t_vector2 *coord_ray, int i)
{
	float		line_height;
	t_vector2	tex;
	t_vector2	start;
	int			side;
	float		scale;

	line_height = 32 * 1080 / dist_ray;
	start = vector2(i * 18, 540 - line_height / 2);
	side = get_side_wall(coord_ray, data->player);
	scale = data->texture[side]->size.x / 64;
	while (start.y < line_height + 540 - line_height / 2)
	{
		start.x = i * 18;
		while (start.x < (i * 18) + 18)
		{
			tex = get_src_pixel(start, line_height, coord_ray, side, data->texture[side]->size.y);
			copy_pixel(get_engine()->win[1], data->texture[side], start, tex);
			start.x++;
		}
		start.y++;
	}
}

static void	draw_ceil_floor(t_map *map_data)
{
	t_vector2	start;
	int			color;

	start = vector2(0, 0);
	color = create_trgb(map_data->ceiling->a, map_data->ceiling->r,
			map_data->ceiling->g, map_data->ceiling->b);
	while (start.y < 540)
	{
		start.x = 0;
		while (start.x < 1080)
		{
			pixel_put(get_engine()->win[1]->renderer.b_back, start, color);
			start.x++;
		}
		start.y++;
	}
	start = vector2(0, 540);
	color = create_trgb(map_data->floor->a, map_data->floor->r,
			map_data->floor->g, map_data->floor->b);
	while (start.y < 1080)
	{
		start.x = 0;
		while (start.x < 1080)
		{
			pixel_put(get_engine()->win[1]->renderer.b_back, start, color);
			start.x++;
		}
		start.y++;
	}
}

int	update_game(void *obj)
{
	t_data	*data;
	t_vector2	coord_ray;
	float	angle;
	float	ray;
	float	off_angle;
	int		i;

	i = 0;
	data = (t_data *)obj;
	event_player_2d(data->player);
	draw_ceil_floor(data->map_data);
	angle = data->player->obj->trans.rot.x - ((FOV / 2) * DR);
	while (i < FOV)
	{
		if (angle > 2 * PI)
			angle -= 2 * PI;
		else if (angle < 0)
			angle += 2 * PI;
		ray = get_ray(data, angle, i, &coord_ray);
		off_angle = angle - data->player->obj->trans.rot.x;
		if (off_angle > 2 * PI)
			off_angle -= 2 * PI;
		else if (off_angle < 0)
			off_angle += 2 * PI;
		ray *= cos(fabs(off_angle));
		draw_3d_pov(ray, data, &coord_ray , i);
		angle += DR;
		i++;
	}
	return (SUCCESS);
}
