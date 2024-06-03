/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:09:41 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 16:08:20 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hud.h"

static void	pixel_put_player(t_win *win, t_vector2 coord, int color)
{
	int				offset;
	t_buffer		*buffer;

	buffer = win->renderer.b_back;
	if (!(coord.x >= 0
			&& coord.y >= 0
			&& coord.x < win->width
			&& coord.y < win->height
		))
	{
		return ;
	}
	offset = (roundf(coord.y) * buffer->l_length
			+ roundf(coord.x) * (buffer->bpp / 8));
	*(unsigned int *)(buffer->addr + offset) = color;
}

void	draw_player(t_texture *texture)
{
	t_vector2	pos;
	t_vector2	pixel;
	int			color;
	int			transparency;
	int			scale;

	scale = 8;
	pos.x = WIN_WIDTH / 2 - (texture->size.x * scale) / 2;
	pos.y = WIN_HEIGHT - (texture->size.y * scale);
	pixel.x = 0;
	while (pixel.x < texture->size.x)
	{
		pixel.y = 0;
		while (pixel.y < texture->size.y)
		{
			for (int i = 0; i < scale; i++) {
				for (int j = 0; j < scale; j++) {
					color = take_pixel(texture, vector2(pixel.x, pixel.y));
					transparency = (color & 0xFF000000) >> 24;
					if (transparency != 0)
						continue ;
					pixel_put_player(__get_engine()->win[0], vector2(pos.x + pixel.x * scale + i, pos.y + pixel.y * scale + j), color);
				}
			}
			pixel.y++;
		}
		pixel.x++;
	}
}

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

static void	run_animation(t_data *data)
{
	static int	iter;

	if (data->player->keys.shift == 14)
		iter = 1;
	data->player->keys.shift += iter;
	if (data->player->keys.shift == 22)
		iter = -1;
	draw_player(data->texture_player[data->player->keys.shift]);
}

int	update_render(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	draw_ceil_floor(data->map_data);
	raycaster(data, data->player);
	if (data->player->keys.fire > 0)
	{
		draw_player(data->texture_player[data->player->keys.fire]);
		data->player->keys.fire--;
	}
	else if (data->player->keys.reload > 2)
	{
		draw_player(data->texture_player[data->player->keys.reload]);
		usleep(950);
		data->player->keys.reload--;
	}
	else
	{
		if (data->player->keys.shift != 0)
			run_animation(data);
		else
			draw_player(data->texture_player[0]);
	}
	update_hud(data);
	return (SUCCESS);
}
