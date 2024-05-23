/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:57 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/23 18:43:28 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	get_side_wall(t_vector2 *ray, t_player *player)
// {
// 	t_vector2	vector;
// 	static int	old_side;

// 	vector = sub_vector2(*ray, player->obj->trans.pos);
// 	if ((int)(ray->y - 32) % 64 == 0 && (int)(ray->x - 32) % 64 != 0)
// 	{
// 		if (vector.y < 0)
// 			old_side = NO;
// 		else
// 			old_side = SO;
// 	}
// 	else if ((int)(ray->x - 32) % 64 == 0 && (int)(ray->y - 32) % 64 != 0)
// 	{
// 		if (vector.x < 0)
// 			old_side = EA;
// 		else
// 			old_side = WE;
// 	}
// 	return (old_side);
// }



// static void	draw_ceil_floor(t_map *map_data)
// {
// 	t_vector2	start;
// 	int			color;

// 	start = vector2(0, 0);
// 	color = create_trgb(map_data->ceiling->a, map_data->ceiling->r,
// 			map_data->ceiling->g, map_data->ceiling->b);
// 	while (start.y < 540)
// 	{
// 		start.x = 0;
// 		while (start.x < 1080)
// 		{
// 			pixel_put(get_engine()->win[1]->renderer.b_back, start, color);
// 			start.x++;
// 		}
// 		start.y++;
// 	}
// 	start = vector2(0, 540);
// 	color = create_trgb(map_data->floor->a, map_data->floor->r,
// 			map_data->floor->g, map_data->floor->b);
// 	while (start.y < 1080)
// 	{
// 		start.x = 0;
// 		while (start.x < 1080)
// 		{
// 			pixel_put(get_engine()->win[1]->renderer.b_back, start, color);
// 			start.x++;
// 		}
// 		start.y++;
// 	}
// }

int	update_game(void *obj)
{
	t_data	*data;
	t_vector2	coord_ray;
	float	angle;
	float	ray;
	float	off_angle;
	int		i;

	i = 0;
	data = (t_data *)obj;
	event_player_2d(data->player);
	draw_ceil_floor(data->map_data);
	angle = data->player->obj->trans.rot.x - ((FOV / 2) * DR);
	while (i < FOV)
	{
		if (angle > 2 * PI)
			angle -= 2 * PI;
		else if (angle < 0)
			angle += 2 * PI;
		ray = get_ray(data, angle, i, &coord_ray);
		off_angle = angle - data->player->obj->trans.rot.x;
		if (off_angle > 2 * PI)
			off_angle -= 2 * PI;
		else if (off_angle < 0)
			off_angle += 2 * PI;
		ray *= cos(fabs(off_angle));
		draw_3d_pov(ray, data, &coord_ray , i);
		angle += DR;
		i++;
	}
	return (SUCCESS);
}
