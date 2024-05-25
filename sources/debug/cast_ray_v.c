/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:56:57 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/23 10:15:29 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector2	next_intersection_v(char **map, t_vector2 point, float angle)
{
	t_vector2	intersection;
	int			map_x;
	int			map_y;
	int			dov;
	float		ntan;

	ntan = -tan(angle);
	intersection = point;
	dov = 0;
	while (dov < 20)
	{
		if (angle < PI / 2 || angle > 3 * PI / 2)
		{
			intersection.y += -(-64 * ntan);
			intersection.x += 64;
		}
		else if (angle > PI / 2 && angle < 3 * PI / 2)
		{
			intersection.y += -(64 * ntan);
			intersection.x += -64;
		}
		if (check_map(map, intersection, angle) == true)
			break ;
		dov++;
	}
	return (intersection);
}

t_vector2	cast_ray_v(char **map ,t_vector2 start, float angle)
{
	t_vector2	point;
	t_vector2	raiser;
	float		step;

	if (angle < PI / 2 || angle > 3 * PI / 2)
	{
        // printf("je regarde a droite\n");
		point.x = ((((int)start.x + 32) >> 6) << 6) + 32;
		point.y = (start.x - point.x) * tan(angle) + start.y;
	}
	else if (angle > PI / 2 && angle < 3 * PI / 2)
	{
        // printf("je regarde a gauche\n");
		point.x = ((((int)start.x + 32) >> 6) << 6) - 32;
		point.y = (start.x - point.x) * tan(angle) + start.y;
	}
	else if (angle == PI || angle == 0)
	{
		return (start);
	}
	if (check_map(map, point, angle) == true)
		return (point);
	return (next_intersection_v(map, point, angle));
}