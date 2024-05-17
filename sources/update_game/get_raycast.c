/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:57 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/17 07:32:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_pixel3d(t_buffer *dst, t_img *src, t_vector2 dst_c, t_vector2 src_c)
{
	int	color;
	int	offset;

	offset = (roundf(src_c.y) * src->l_length
			+ roundf(src_c.x) * (src->bpp / 8));
	color = create_trgb(src->addr[offset + 3], src->addr[offset + 2],
			src->addr[offset + 1], src->addr[offset]);
	pixel_put(dst, dst_c, color);
}

static void	draw_3d_pov(float dist_ray, t_data *data, t_vector2 *coord_ray, int i)
{
	float		line_height;
	t_vector2	src;
	t_vector2	start;

	line_height = 32 * 1080 / dist_ray;
	if (line_height > 1080)
		line_height = 1080;
	start = vector2(i * 18, 540 - line_height / 2);
	while (start.y < line_height + 540 - line_height / 2)
	{
		start.x = i * 18;
		while (start.x < (i * 18) + 18)
		{
			copy_pixel3d(get_engine()->win[1]->renderer.b_back, data->texture_img[0], start, vector2((int)(coord_ray->x - 32) % 64, (int)(coord_ray->y - 32.0) % 64));
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
	while (i < 60)
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
