/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:09:41 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 14:40:20 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_3d(t_ray *ray, t_data *data, int x)
{
	t_vector2	texture;
	float		shade;
	int			y;
	int			color;

	shade = 1.0;
	if (ray->hit_axis == VERTICAL)
		shade = 1 / (ray->dir.y * ray->dir.y + ray->dir.x * ray->dir.x + 0.5);
	texture = get_coord_texture(ray, data);
	y = (int)ray->draw_start;
	while (y <= ray->draw_end)
	{
		color = take_pixel(data->texture[ray->index_texture], texture);
		color = apply_shade(color, shade);
		pixel_put(__get_engine()->win[0], vector2(x, y), color);
		texture.y += ray->step_texture_wall;
		y++;
	}
}

int	update(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	event_player_2d(data->player);
	draw_ceil_floor(data->map_data);
	raycaster(data, data->player);
	return (SUCCESS);
}
