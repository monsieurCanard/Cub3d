/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:06:37 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/19 18:48:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map(t_map *map, t_vector2 point, float angle)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	map_x = ((int)point.x + 32) / 64;
	if (angle < PI)
	{
		map_y = -((int)point.y - 32) / 64;
	}
	else if (angle > PI)
	{	
		map_y = -((int)point.y + 32) / 64;
	}
	if (map_x >= 0 && map_y >= 0 && map_x < (int)map->size_x
		&& map_y < (int)map->size_z && map->map[map_y][map_x] == '1')
		return (true);
	return (false);
}

static t_vector2	next_intersection(t_map *map, t_vector2 point, float angle)
{
	t_vector2	intersection;
	int			dov;
	float		atan;

	atan = -1 / tan(angle);
	intersection = point;
	dov = 0;
	while (dov < 10)
	{
		if (check_map(map, intersection, angle) == true)
			break ;
		if (angle > PI)
		{
			intersection.x -= -64 * atan;
			intersection.y += 64;
		}
		else if (angle < PI)
		{
			intersection.x -= 64 * atan;
			intersection.y -= 64;
		}
		dov++;
	}
	return (intersection);
}

t_vector2	cast_ray_h(t_map *map, t_vector2 start, float angle)
{
	t_vector2	point;

	point = start;
	if (angle == 0 || angle == PI)
		return (point);
	if (angle < PI)
	{
		point.y = ((((int)start.y + 32) >> 6) << 6) - 32;
		point.x = (start.y - point.y) / tan(angle) + start.x;
	}
	else if (angle > PI)
	{
		point.y = ((((int)start.y + 32) >> 6) << 6) + 32;
		point.x = (start.y - point.y) / tan(angle) + start.x;
	}
	return (next_intersection(map, point, angle));
}
