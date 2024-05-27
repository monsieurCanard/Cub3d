/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:02:04 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/27 10:05:45 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data)
{
	t_vector2	pos;
	t_vector2	pixel;
	t_engine	*engine;
	int 		scale;

	scale = 15;
	engine = get_engine();
	pos.x = WIN_WIDTH / 2 - (data->texture[4]->size.x * scale) / 2;
	pos.y = WIN_HEIGHT - (data->texture[4]->size.y * scale);
	pixel.x = 0;
	while (pixel.x < data->texture[4]->size.x)
	{
		pixel.y = 0;
		while (pixel.y < data->texture[4]->size.y)
		{
			for (int i = 0; i < scale; i++) {
				for (int j = 0; j < scale; j++) {
					copy_pixel(engine->win[0], data->texture[4], vector2(pos.x + pixel.x*scale + i, pos.y + pixel.y*scale + j), vector2(pixel.x, pixel.y), 1.0);
				}
			}
			pixel.y++;
		}
		pixel.x++;
	}
}