/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:46:11 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/27 09:30:24 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int get_side_wall(t_ray *ray, int hit_axis)
{
	if (hit_axis == VERTICAL)
	{
		if (ray->dir.y > 0)
			return (WE);
		else
			return (EA);
	}
	else
	{
		if (ray->dir.x < 0)
			return (NO);
		else
			return (SO);
	}
}

static void	launch_ray(t_ray *ray, t_data *data)
{
	int	touch_wall;

	touch_wall = 0;
	while (touch_wall == 0)
	{
		if (ray->dist.x < ray->dist.y)
		{
			ray->dist.x += ray->delta.x;
			ray->map_x += ray->step.x;
			ray->hit_axis = HORIZONTAL;
		}
		else
		{
			ray->dist.y += ray->delta.y;
			ray->map_y += ray->step.y;
			ray->hit_axis = VERTICAL;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_x > data->map_data->size_z - 0.25
			|| ray->map_y > data->map_data->size_x - 1.25)
		{
			break ;
		}
		if (data->map_data->map[ray->map_x][ray->map_y] == '1')
		{
			touch_wall = 1;
		}
	}
}

void	raycaster(t_data *data, t_player *player)
{
	t_ray		ray;
	int			x;

	x = 0;
	ft_bzero(&ray, sizeof(t_ray));
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, player, x);
		init_step(&ray, player);
		launch_ray(&ray, data);
		calcul_wall(&ray, player);
	    ray.index_texture = get_side_wall(&ray, ray.hit_axis);
		update_3d(&ray, data, x);
		x++;
	}
}