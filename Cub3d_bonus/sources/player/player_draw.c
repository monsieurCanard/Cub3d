/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:51:19 by monsieurc         #+#    #+#             */
/*   Updated: 2024/06/03 18:21:28 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_player(t_texture *texture, t_vector2 pos,
	t_vector2 pixel, int scale)
{
	int	i;
	int	j;
	int	color;
	int	transparency;

	i = 0;
	while (i++ < scale)
	{
		j = 0;
		while (j++ < scale)
		{
			color = take_pixel(texture, pixel);
			transparency = (color & 0xFF000000) >> 24;
			if (transparency > 0)
			{
				j++;
				continue ;
			}
			pixel_put(__get_engine()->win[0],
				vector2(pos.x + pixel.x * scale + i,
					pos.y + pixel.y * scale + j), color);
		}
	}
}

void	draw_texture_player(t_texture *texture)
{
	t_vector2	pos;
	t_vector2	pixel;
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
			draw_player(texture, pos, pixel, scale);
			pixel.y++;
		}
		pixel.x++;
	}
}
