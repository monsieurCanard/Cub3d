/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:23:42 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 10:36:35 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>

static bool	check_map(t_map *map, t_vector2 point, float angle)
{
	int	map_x;
	int	map_y;

	map_x = 0;
	map_y = -((int)point.y - 32) / 64;
	if (angle < PI / 2 || angle > 3 * PI / 2)
	{
		map_x = ((int)point.x + 32) / 64;
	}
	else if (angle > PI / 2 && angle < 3 * PI / 2)
	{
		map_x = ((int)point.x - 32) / 64;
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

	atan = -tan(angle);
	intersection = point;
	dov = 0;
	while (dov < 10)
	{
		if (check_map(map, intersection, angle) == true)
			break ;
		if (angle < PI / 2 || angle > 3 * PI / 2)
		{
			intersection.y -= (-64 * atan);
			intersection.x += 64;
		}
		else if (angle > PI / 2 && angle < 3 * PI / 2)
		{
			intersection.y -= (64 * atan);
			intersection.x -= 64;
		}
		dov++;
	}
	return (intersection);
}

t_vector2	cast_ray_v(t_map *map, t_vector2 start, float angle)
{
	t_vector2	point;

	point = start;
	if (angle == 0 || angle == PI)
		return (point);
	if (angle < PI / 2 || angle > 3 * PI / 2)
	{
		point.x = ((((int)start.x + 32) >> 6) << 6) + 32;
		point.y = (start.x - point.x) * tan(angle) + start.y;
	}
	else if (angle > PI / 2 && angle < 3 * PI / 2)
	{
		point.x = ((((int)start.x + 32) >> 6) << 6) - 32;
		point.y = (start.x - point.x) * tan(angle) + start.y;
	}
	return (next_intersection(map, point, angle));
}
