/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:46:11 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/31 10:26:51 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_out_of_map(t_ray *ray, t_data *data)
{
	if (ray->map_y < 0.25
		|| ray->map_x < 0.25
		|| ray->map_x > data->map_data->size_z - 0.25
		|| ray->map_y > data->map_data->size_x - 1.25)
	{
		return (true);
	}
	return (false);
}

static void	hit_axis(t_ray *ray, int side_wall)
{
	if (side_wall == VERTICAL)
	{
		ray->dist.y += ray->delta.y;
		ray->map_y += ray->step.y;
		ray->hit_axis = VERTICAL;
	}
	else if (side_wall == HORIZONTAL)
	{
		ray->dist.x += ray->delta.x;
		ray->map_x += ray->step.x;
		ray->hit_axis = HORIZONTAL;
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
			hit_axis(ray, HORIZONTAL);
		}
		else
		{
			hit_axis(ray, VERTICAL);
		}
		if (is_out_of_map(ray, data))
		{
			break ;
		}
		if (data->map_data->map[ray->map_x][ray->map_y] == '1'
			|| data->map_data->map[ray->map_x][ray->map_y] == 'P')
		{
			touch_wall = 1;
		}
	}
}

static int	get_side_wall(t_ray *ray, int hit_axis, t_data *data)
{
	if (data->map_data->map[ray->map_x][ray->map_y] == 'P')
		return (4);
	if (hit_axis == VERTICAL)
	{
		if (ray->dir.y > 0)
			return (WE);
		else
		{
			if (data->map_data->map[ray->map_x][ray->map_y] == '1'
				&& data->map_data->map[ray->map_x][ray->map_y - 1] == 'C')
				return (5);
			else
				return (EA);
		}
	}
	else
	{
		if (ray->dir.x > 0)
			return (NO);
		else
			return (SO);
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
		ray.index_texture = get_side_wall(&ray, ray.hit_axis, data);
		update_3d(&ray, data, x);
		x++;
	}
}
