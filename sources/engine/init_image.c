/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:37:38 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 22:19:33 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_img	*init_xpm_img(void *p_engine, char *file, int width, int height)
{
	t_img		*img;
	t_engine	*engine;

	engine = (t_engine *)p_engine;
	img = ft_calloc(1, sizeof(t_img));
	if (!img)
	{
		perror("Error malloc");
		return (NULL);
	}
	img->img_ptr = mlx_xpm_file_to_image(engine->mlx_ptr, file, &width, &height);
	if (!img->img_ptr)
	{
		perror("Error ptr");
		return (NULL);
	}
	img->pixel_ptr = mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->size_line,
			&img->endian);
	img->color_offset = 1;
	return (img);
}

void	put_img_to_window(void *p_engine, t_img *img, int x, int y)
{
	t_engine	*engine;

	engine = (t_engine *)p_engine;
	mlx_put_image_to_window(engine->mlx_ptr, engine->win_ptr, img->img_ptr, x, y);
}
