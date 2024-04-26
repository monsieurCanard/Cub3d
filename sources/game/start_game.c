/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:03:34 by antgabri          #+#    #+#             */
/*   Updated: 2024/04/26 14:17:32 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_game(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fabs(data->player.x - x) < 5 && fabs(data->player.y - y) < 5)
				my_pixel_put(&data->img, x, y, RED);
			else
				my_pixel_put(&data->img, x, y, BLACK);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}

void	start_game(t_data *data)
{
	create_player(data);
	create_game(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_window, data);
	mlx_loop(data->mlx_ptr);
}
