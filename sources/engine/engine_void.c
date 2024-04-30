/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:24:14 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 17:15:59 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	__create_void(t_engine *engine)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(&engine->e_void, x, y, VOID_COLOR);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr,
		engine->e_void.img_ptr, 0, 0);
	mlx_hook(engine->win_ptr, 17, 1L << 17, close_window, engine);
	mlx_hook(engine->win_ptr, 2, 1L << 0, key_press, engine);
	mlx_loop(engine->mlx_ptr);
	return ;
}