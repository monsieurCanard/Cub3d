/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:09:41 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/25 12:29:25 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_ray *ray, t_player *player, int x)
{
	ft_bzero(ray, sizeof(t_ray));
	ray->angle = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir = vector2(player->dir.x + player->plane.x * ray->angle,
			player->dir.y + player->plane.y * ray->angle);
	ray->delta = vector2(fabs(1 / ray->dir.x), fabs(1 / ray->dir.y));
	ray->map_x = (int)player->pos.x;
	ray->map_y = (int)player->pos.y;
}

static void	init_step(t_ray *ray, t_player *player)
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

static int	get_side_wall(t_ray *ray, t_player *player, int hit_axis)
{
	if (hit_axis == 1)
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
			ray->hit_axis = 0;
		}
		else
		{
			ray->dist.y += ray->delta.y;
			ray->map_y += ray->step.y;
			ray->hit_axis = 1;
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

static void	calcul_wall(t_ray *ray, t_player *player)
{
	if (ray->hit_axis == 0)
		ray->wall_dist = ray->dist.x - ray->delta.x;
	else
		ray->wall_dist = ray->dist.y - ray->delta.y;
	ray->line_height = WIN_HEIGHT / ray->wall_dist;
	ray->draw_start = -(ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->hit_axis == 0)
		ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->index_texture = get_side_wall(ray, player, ray->hit_axis);
}

static void	update_3d(t_ray *ray, t_data *data, int x)
{
	t_vector2	texture;
	float		step;
	float		shade;
	int 		y;

	if (ray->hit_axis == 1)
		shade = 1 / (ray->dir.y * ray->dir.y + ray->dir.x * ray->dir.x + 0.1);
	else
		shade = 1.0;
	texture.x = (int)(ray->wall_x * data->texture[0]->size.x);
	if ((ray->hit_axis == 0 && ray->dir.x > 0) || (ray->hit_axis == 1 && ray->dir.y < 0))
		texture.x = data->texture[0]->size.x - texture.x - 1;
	step = 1.0 * data->texture[0]->size.y / ray->line_height;
	texture.y = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		texture.y += step;
		copy_pixel(get_engine()->win[0], data->texture[ray->index_texture], vector2(x, y), texture, shade);
		y++;
	}
}

static void	raycaster(t_data *data, t_player *player)
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
		update_3d(&ray, data, x);
		x++;
	}
}
int	update(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	event_player_2d(data->player);
	draw_ceil_floor(data->map_data);
	raycaster(data, data->player);
	// cast_60_ray(data);
	return (0);
}

// static int	get_side_wall(t_vector2 vector_ray, int hit_axis)
// {
// 	if (hit_axis == 1)
// 	{
// 		if (vector_ray.x < 0)
// 			return (WE);
// 		else
// 			return (EA);
// 	}
// 	else
// 	{
// 		if (vector_ray.y < 0)
// 			return (NO);
// 		else
// 			return (SO);
// 	}
// }

// // t_vector2	get_src_pixel(t_vector2 start, int line_height, t_vector2 *ray, int side, int size_y)
// // {
// // 	t_vector2	src;

// // 	src.y = roundf((start.y - (WIN_HEIGHT / 2) + line_height / 2) * size_y / line_height);
// // 	if (side == NO)
// // 		src.x = fabs(64 - (int)((ray->x - 32)) % 64 + start.x);
// // 	else if (side == SO)
// // 		src.x = fabs((int)(ray->x - 32) % 64 + start.x);
// // 	else if (side == EA)
// // 		src.x = fabs(64 + (int)(ray->y - 32) % 64 + start.x);
// // 	else
// // 		src.x = fabs((int)(ray->y - 32) % 64 + start.x);
// // 	return (src);
// // }

// t_vector2 get_src_pixel(t_ray *ray, t_vector2 start, int line_height, t_player *p, int x, float ppc)
// {
// 	t_vector2	src;
// 	float		step;
// 	float		wall_x;

// 	src = vector2(0, 0);
// 	step = 1.0 * 64 / line_height;
// 	src.y = fabs((start.y - (WIN_HEIGHT / 2) + line_height / 2) * step);
// 	// src.x = fabs(start.x - (WIN_WIDTH / 2)) / ppc;
// 	wall_x = ray->hit_axis == 1 ? p->obj->trans.pos.y + ray->dist * ray->vector.y : p->obj->trans.pos.x + ray->dist * ray->vector.x;
// 	wall_x -= floor(wall_x);
// 	src.x = fabs(wall_x * 64);
// 	return (src);
// }

// static void	draw_3d_pov(t_data *data, t_ray *ray, int i)
// {
// 	float		line_height;
// 	t_vector2	tex;
// 	t_vector2	start;
// 	t_vector2	end;
// 	t_vector2	src;
// 	int			side;
// 	float		scale;

// 	line_height = (WIN_HEIGHT / ray->dist) * 32;
// 	// printf("line = %f\n", line_height);	
// 	// printf ("ppc = %f\n", (18 / ray->dist) * 32);
// 	start = vector2(0, -(line_height / 2) + (WIN_HEIGHT / 2));
// 	side = get_side_wall(ray->vector, ray->hit_axis);
// 	scale = data->texture[side]->size.x / 64;
// 	src = vector2(0, 0);
// 	end.y = line_height / 2 + (WIN_HEIGHT / 2);
// 	if (end.y > WIN_HEIGHT)
// 		end.y = WIN_HEIGHT - 1;
// 	end.x = i * WIN_WIDTH / FOV + WIN_WIDTH / FOV;
// 	if (end.x > WIN_WIDTH)
// 		end.x = WIN_WIDTH - 1;
// 	while (start.y < end.y)
// 	{
// 		start.x = i * WIN_WIDTH / FOV;
// 		src.x = 0;
// 		while (start.x < end.x)
// 		{
// 			tex = get_src_pixel(ray, start, line_height, data->player, src.x, (18 / ray->dist) * 32);
// 			copy_pixel(get_engine()->win[1], data->texture[side], start, tex);
// 			start.x++;
// 			src.x++;
// 		}
// 		start.y++;
// 		src.y++;
// 	}
// }

// void	cast_60_ray(t_data *data)
// {
// 	float		angle;
// 	int			i;
// 	float		fisheye_correc;
// 	t_ray		ray;

// 	i = 0;
// 	angle = data->player->obj->trans.rot.x - ((FOV / 2) * DR);
// 	while (i < FOV)
// 	{
// 		angle = cap_angle_rad(angle);
// 		ray.end = cast_ray(angle, data, &ray.hit_axis, i);
// 		ray.vector = sub_vector2(ray.end, data->player->obj->trans.pos);
// 		ray.dist = magnitude_vector2(ray.vector);
// 		fisheye_correc = cap_angle_rad(angle - data->player->obj->trans.rot.x);
// 		ray.dist *= cos(fabs(fisheye_correc));
// 		ray.angle = angle;
// 		draw_3d_pov(data, &ray, i);
// 		angle += DR;
// 		i++;
// 	}
// }