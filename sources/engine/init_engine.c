/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:09:13 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/04/26 22:11:34 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void take_close_io(t_engine *engine)
{
	mlx_hook(engine->win_ptr, 17, 1L << 17, close_window, engine);
	mlx_hook(engine->win_ptr, 2, 1L << 0, key_press, engine);
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
	__create_void(engine);
	take_close_io(engine);
	return (engine);
}
