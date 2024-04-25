/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:09:13 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2024/04/25 16:18:41 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, WEIGHT);
	if (!data->img_ptr)
	{
		printf(ERROR_IMAGE);
		mlx_destroy_windows(data->mlx_ptr, mlx_win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (EXIT_FAILURE);
	}
	data->img.pixel_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.size_line, &data->img.endian);
	data->img.color_offset = 1;
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		printf(ERROR_MLX_INIT);
		exit (EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, WEIGHT, "cub3D");
	if (!data->win_ptr)
	{
		printf(ERROR_INIT_WINDOWS);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (EXIT_FAILURE);
	}
	init_image(data);
}
