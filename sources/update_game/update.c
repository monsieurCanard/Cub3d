/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:09:41 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 18:22:35 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hud.h"

void	update_3d(t_ray *ray, t_data *data, int x)
{
	t_vector2	texture;
	float		shade;
	int			y;
	int			color;

	y = (int)ray->draw_start;
	shade = 1.0;
	if (ray->hit_axis == VERTICAL)
		shade = 1 / (ray->dir.y * ray->dir.y + ray->dir.x * ray->dir.x + 0.5);
	texture = get_coord_texture(ray, data);
	while (y <= ray->draw_end)
	{
		color = take_pixel(data->texture[ray->index_texture], texture);
		color = apply_shade(color, shade);
		pixel_put(__get_engine()->win[0], vector2(x, y), color);
		texture.y += ray->step_texture_wall;
		y++;
	}
}

int	update_logic(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	event_player_2d(data);
	return (SUCCESS);
}

int	update_render(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	draw_ceil_floor(data->map_data);
	raycaster(data, data->player);
	update_player(data);
	update_hud(data);
	return (SUCCESS);
}
