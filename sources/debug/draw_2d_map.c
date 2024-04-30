/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/30 17:40:40 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <core_engine.h>

int	init_debug_img(t_img **empty_img, t_img **full_img, t_img **cam_img)
{
	*empty_img = init_xmp_img("./debug/texture/empty.xpm");
	*full_img = init_xmp_img("./debug/texture/full.xpm");
	*cam_img = init_xmp_img("./debug/texture/cam.xpm");
	if (*empty_img == NULL || *full_img == NULL)
	{
		perror("Error\n");
		return (FAILURE);
	}
	if ((*empty_img)->addr == NULL || (*full_img)->addr == NULL)
	{
		perror("Error\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

void	create_wall(t_img *img, int x, int y, size_t nb_obj)
{
	t_object2d	*obj;

	obj = new_obj2d("wall", nb_obj);
	obj->coord->x = x;
	obj->coord->y = y;
	obj->img = img;
}

void	create_debug_map(t_map *map)
{
	t_img	*empty_img;
	t_img	*full_img;
	t_img	*cam_img;
	t_camera	*cam;
	t_object2d	*cam_obj;
	size_t	nb_obj;
	size_t	x;
	size_t	y;

	init_debug_img(&empty_img, &full_img, &cam_img);
	y = 0;
	nb_obj = 0;
	while (y < map->size_z)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->map[y][x] == '1')
			{
				create_wall(full_img, x * 25, -(y * 25), nb_obj);
				nb_obj++;
			}
			else if (map->map[y][x] == '0')
			{
				create_wall(empty_img, x * 25, -(y * 25), nb_obj);
				nb_obj++;
			}
			else if (map->map[y][x] == 'N')
			{
				cam = new_camera();
				cam->coord->x = (int)-(x * 25);
				cam->coord->y = (int)-(y * 25);
				cam_obj = new_obj2d("cam", 499);
				cam_obj->coord->x = (int)(x * 25);
				cam_obj->coord->y = (int)-(y * 25);
				cam_obj->img = cam_img;
				create_wall(empty_img, x * 25, -(y * 25), nb_obj);
				nb_obj++;
			}
			x++;
		}
		y++;
	}
}
