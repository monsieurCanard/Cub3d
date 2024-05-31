/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:47:46 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/31 14:25:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"

static void	draw_square(t_texture *texture, t_vector2 start,
	t_vector2 size, int color)
{
	int	x;
	int	y;
	int	offset;

	x = 0;
	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			offset = (start.x + x) * texture->l_length
				+ (start.y + y) * (texture->bpp / 8);
			*(unsigned int *)(texture->addr + offset) = color;
			y++;
		}
		x++;
	}
}

static void	draw_map_texture(t_texture *minimap, t_map *map)
{
	int	x;
	int	z;

	x = 0;
	while (x < (int)map->size_x)
	{
		z = 0;
		while (z < (int)map->size_z)
		{
			if (map->map[z][x] == '1')
				draw_square(minimap, vector2(z * 10, x * 10),
					vector2(10, 10), 0x00FF00);
			else if (map->map[z][x] == '0' || map->map[z][x] == 'N' || map->map[z][x] == 'S' || map->map[z][x] == 'E' || map->map[z][x] == 'W')
				draw_square(minimap, vector2(z * 10, x * 10),
					vector2(10, 10), 0xFF0000);
			else
				draw_square(minimap, vector2(z * 10, x * 10),
					vector2(10, 10), 0x000000);
			z++;
		}
		x++;
	}
}

t_texture	*init_minimap(t_map *map)
{
	t_texture	*minimap;

	minimap = init_void_texture(vector2(map->size_x * 10, map->size_z * 10));
	if (minimap == NULL)
	{
		logerror(__FILE__, __LINE__, "init_void_texture() failed");
		return (NULL);
	}
	draw_map_texture(minimap, map);
	return (minimap);
}
