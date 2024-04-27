/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:24:14 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 21:24:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	__init_void_img(t_engine *engine)
{
	engine->e_void.img_ptr = mlx_new_image(engine->mlx_ptr, WIDTH, HEIGHT);
	if (!engine->e_void.img_ptr)
	{
		printf(ERROR_IMAGE);
		mlx_destroy_window(engine->mlx_ptr, engine->win_ptr);
		mlx_destroy_display(engine->mlx_ptr);
		free(engine->mlx_ptr);
		exit (EXIT_FAILURE);
	}
	engine->e_void.pixel_ptr = mlx_get_data_addr(engine->e_void.img_ptr,
			&engine->e_void.bpp, &engine->e_void.size_line,
			&engine->e_void.endian);
	engine->e_void.color_offset = 1;
}

void	__create_void(t_engine *engine)
{
	size_t	x;
	size_t	y;

	__init_void_img(engine);
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
}