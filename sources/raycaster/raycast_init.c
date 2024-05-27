/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:42:14 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/26 10:38:49 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->angle = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir = vector2(player->dir.x + player->plane.x * ray->angle,
			player->dir.y + player->plane.y * ray->angle);
	ray->delta = vector2(fabs(1 / ray->dir.x), fabs(1 / ray->dir.y));
	ray->map_x = (int)player->pos.x;
	ray->map_y = (int)player->pos.y;
}

void	init_step(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->dist.x = (player->pos.x - ray->map_x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->dist.x = (ray->map_x + 1.0 - player->pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->dist.y = (player->pos.y - ray->map_y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->dist.y = (ray->map_y + 1.0 - player->pos.y) * ray->delta.y;
	}
	//TODO REFACTo
}
