/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:57 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/21 15:51:25 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_3d_pov(float dist_ray, t_data *data,
	t_vector2 *coord_ray, int i)
{
	float		line_height;
	t_vector2	src;
	t_vector2	start;
	int 		tex_x;

	line_height = 32 * 1080 / dist_ray;
	if (line_height > 1080)
		line_height = 1080;
	start = vector2(i * 18, 540 - line_height / 2);
	while (start.y < line_height + 540 - line_height / 2)
	{
		start.x = i * 18;
		while (start.x < (i * 18) + 18)
		{
			float tex_pos = (start.y - (540 - line_height / 2)) / line_height;
			int tex_y = (int)(tex_pos * 64);
			//TODO Savoir de quelle cote on tape un mur pour savoir comment afficher la texture
			// if (angle > PI)
    		tex_x = (int)(coord_ray->x - 32) % 64;
			// else
    		// 	tex_x =  64 - (int)(coord_ray->x - 32) % 64;
			// tex_x = 64 -(int)(coord_ray->y - 32) % 64;
			copy_pixel(get_engine()->win[1], data->texture[0], start,
				vector2(tex_x, tex_y));
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
		draw_3d_pov(ray, data, &coord_ray , i, data->player->obj->trans.rot.x);
		angle += DR;
		i++;
	}
	return (SUCCESS);
}
