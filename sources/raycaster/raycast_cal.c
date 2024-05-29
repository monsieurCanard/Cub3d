/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_cal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:50:15 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/29 14:19:56 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector2	get_coord_texture(t_ray *ray, t_data *data)
{
	t_vector2	texture;

	texture.x = (ray->wall_x * data->texture[0]->size.x);
	if ((ray->hit_axis == 0 && ray->dir.x > 0)
		|| (ray->hit_axis == 1 && ray->dir.y < 0))
		texture.x = data->texture[0]->size.x - texture.x;
	ray->step_texture_wall = 1.0 * data->texture[0]->size.y / ray->line_height;
	texture.y = (int)(ray->draw_start -(WIN_HEIGHT / 2)
			+ (ray->line_height / 2)) * ray->step_texture_wall;
	return (texture);
}

static void	set_limits_draw(t_ray *ray)
{
	ray->draw_start = (int)(-(ray->line_height) / 2) + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (int)(ray->line_height / 2) + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	calcul_wall(t_ray *ray, t_player *player)
{
	if (ray->hit_axis == HORIZONTAL)
		ray->wall_dist = ray->dist.x - ray->delta.x;
	else
		ray->wall_dist = ray->dist.y - ray->delta.y;
	ray->line_height = (WIN_HEIGHT / ray->wall_dist) * 0.65;
	set_limits_draw(ray);
	if (ray->hit_axis == HORIZONTAL)
		ray->wall_x = player->pos.y - ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}
