/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:34 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/04 16:57:22 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "core.h"

static int	get_addr(t_texture *texture)
{
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->l_length, &texture->endian);
	if (!texture->addr)
	{
		logwarning(__FILE__, __LINE__, "mlx_get_data_addr() failed");
		return (FAILURE);
	}
	return (SUCCESS);
}

t_texture	*init_texture(const char *path)
{
	t_engine	*engine;
	t_texture	*texture;
	int			width;
	int			height;

	engine = __get_engine();
	texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (texture == NULL)
	{
		logerror(__FILE__, __LINE__, "allocation failed...");
		return (NULL);
	}
	texture->img = mlx_xpm_file_to_image(engine->mlx,
			(char *)path, &width, &height);
	if (texture->img == NULL)
	{
		logerror(__FILE__, __LINE__, "mlx_xpm_file_to_image() failed");
		return (free(texture), NULL);
	}
	texture->size = vector2 (width, height);
	if (get_addr(texture) == FAILURE)
	{
		return (free(texture->img), free(texture), NULL);
	}
	return (texture);
}

t_texture	*init_void_texture(t_vector2 size)
{
	t_texture	*texture;

	texture = (t_texture *)ft_calloc(1, sizeof(t_texture));
	if (texture == NULL)
	{
		logerror(__FILE__, __LINE__, "allocation failed...");
		return (NULL);
	}
	texture->img = mlx_new_image(__get_engine()->mlx, size.x, size.y);
	if (texture->img == NULL)
	{
		logerror(__FILE__, __LINE__, "mlx_new_image() failed");
		free(texture);
		return (NULL);
	}
	get_addr(texture);
	if (texture->addr == NULL)
	{
		return (free(texture->img), free(texture), NULL);
	}
	texture->size = size;
	return (texture);
}

void	destroy_texture(t_texture *texture)
{
	if (texture == NULL)
	{
		logwarning(__FILE__, __LINE__, "the texture is NULL");
		return ;
	}
	mlx_destroy_image(__get_engine()->mlx, texture->img);
	free(texture);
}
