/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:47:46 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 13:19:21 by jbrousse         ###   ########.fr       */
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

static bool	is_floor(const char **map, int x, int z)
{
	if (map[z][x] == '0' || map[z][x] == 'N' || map[z][x] == 'S'
		|| map[z][x] == 'E' || map[z][x] == 'W')
	{
		return (true);
	}
	return (false);
}

static void	draw_element(int x, int z, t_texture *minimap, const char **map)
{
	if (map[z][x] == '1')
		draw_square(minimap, vector2(z * SIZE_SQUARE, x * SIZE_SQUARE),
			vector2(SIZE_SQUARE, SIZE_SQUARE), 0x313036);
	else if (is_floor(map, x, z) == true)
		draw_square(minimap, vector2(z * SIZE_SQUARE, x * SIZE_SQUARE),
			vector2(SIZE_SQUARE, SIZE_SQUARE), 0xC3BAB0);
	else if (map[z][x] == 'P' || map[z][x] == 'C')
		draw_square(minimap, vector2(z * SIZE_SQUARE, x * SIZE_SQUARE),
			vector2(SIZE_SQUARE, SIZE_SQUARE), 0xC52943);
	else
		draw_square(minimap, vector2(z * SIZE_SQUARE, x * SIZE_SQUARE),
			vector2(SIZE_SQUARE, SIZE_SQUARE), 0x000000);
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
			draw_element(x, z, minimap, (const char **)map->map);
			z++;
		}
		x++;
	}
}

t_texture	*init_minimap(t_map *map)
{
	t_texture	*minimap;

	minimap = init_void_texture(vector2(map->size_x * SIZE_SQUARE,
				map->size_z * SIZE_SQUARE));
	if (minimap == NULL)
	{
		logerror(__FILE__, __LINE__, "init_void_texture() failed");
		return (NULL);
	}
	draw_map_texture(minimap, map);
	return (minimap);
}
