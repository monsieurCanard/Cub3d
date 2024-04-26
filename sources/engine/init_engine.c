/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:09:13 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/04/26 17:12:53 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	init_image(t_engine *engine)
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

void	*init_engine(void)
{
	t_engine	*engine;

	engine = ft_calloc(sizeof(t_engine), 1);
	if (!engine)
	{
		printf("ERROR_MALLOC_ENGINE\n");
		exit (EXIT_FAILURE);
	}
	engine->mlx_ptr = mlx_init();
	if (!engine->mlx_ptr)
	{
		printf(ERROR_MLX_INIT);
		exit (EXIT_FAILURE);
	}
	engine->win_ptr = mlx_new_window(engine->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!engine->win_ptr)
	{
		printf(ERROR_INIT_WINDOWS);
		mlx_destroy_display(engine->mlx_ptr);
		free(engine->mlx_ptr);
		exit (EXIT_FAILURE);
	}
	init_image(engine);
	__create_void(engine);
	return (engine);
}
