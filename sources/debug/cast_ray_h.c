/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:54:52 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/14 12:11:16 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector2	next_intersection_h(char **map, t_vector2 point, float angle)
{
	t_vector2	intersection;
	int			map_x;
	int			map_y;
	int			dov;
	float		atan;

	atan = -1 / tan(angle);
	intersection = point;
	dov = 0;
	while (dov < 10)
	{
		if (angle > PI)
		{
			intersection.x += -(-64 * atan);
			intersection.y += 64;
		}
		else if (angle < PI)
		{
			intersection.x += -(64 * atan);
			intersection.y += -64;
		}
		if (check_map(map, intersection, angle) == true)
			break ;
		dov++;
	}
	return (point);
}

t_vector2	cast_ray_h(char **map ,t_vector2 start, float angle)
{
	t_vector2	point;
	t_vector2	raiser;
	float		step;

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
	else if (angle == PI || angle == 0)
	{
		return (start);
	}
	if (check_map(map, point, angle) == true)
		return (point);
	return (next_intersection_h(map, point, angle));
}