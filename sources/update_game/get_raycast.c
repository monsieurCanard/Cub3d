/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:30:57 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/15 17:58:14 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_3d_pov(float dist_ray, int color, int i)
{
	float		line_height;
	t_vector2	start;

	line_height = (800 - (dist_ray - 1)) * 0.75;
	printf("dist_ray = %f\n", dist_ray);
	printf("line_height = %f\n", line_height);
	if (line_height > 800)
		line_height = 800;
	start = vector2(i * 13, 400 - (line_height / 2));
	while (start.y < line_height)
	{
		start.x = i * 13;
		while (start.x < (i * 13) + 13)
		{
			pixel_put(get_engine()->win[1]->renderer.b_back, start, color);
			start.x++;
		}
		start.y++;
	}
}

int	update_game(void *obj)
{
	t_data	*data;
	float	angle;
	float	ray;
	float	off_angle;
	float	norm_ray;
	int		i;

	i = 0;
	data = (t_data *)obj;
	angle = data->player->obj->trans.rot.x - ((FOV / 2) * DR);
	while (i < 60)
	{
		if (angle > 2 * PI)
			angle -= 2 * PI;
		else if (angle < 0)
			angle += 2 * PI;
		ray = get_ray(data, angle, i);
		off_angle = angle - data->player->obj->trans.rot.x;
		if (off_angle > 0)
			off_angle += 2 * PI;
		else if (off_angle < 2 * PI)
			off_angle -= 2 * PI;
		// ray *= cos(off_angle);
		draw_3d_pov(ray, RED, i);
		angle += DR;
		i++;
	}
	return (SUCCESS);
}
