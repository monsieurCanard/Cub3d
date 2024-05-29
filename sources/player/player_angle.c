/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:37:06 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/29 11:10:29 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	p_angle_right(t_player *player)
{
	float		tmp_x;
	t_vector2	p_dir;
	t_vector2	plane;

	p_dir = player->dir;
	plane = player->plane;
	tmp_x = player->dir.x;
	player->dir.x = p_dir.x * cos(0.035 * PI) - p_dir.y * sin(0.035 * PI);
	player->dir.y = tmp_x * sin(0.035 * PI) + p_dir.y * cos(0.035 * PI);
	tmp_x = player->plane.x;
	player->plane.x = plane.x * cos(0.035 * PI) - plane.y * sin(0.035 * PI);
	player->plane.y = tmp_x * sin(0.035 * PI) + plane.y * cos(0.035 * PI);
}

static void	p_angle_left(t_player *player)
{
	float		tmp_x;
	t_vector2	p_dir;
	t_vector2	plane;

	p_dir = player->dir;
	plane = player->plane;
	tmp_x = player->dir.x;
	player->dir.x = p_dir.x * cos(-0.035 * PI) - p_dir.y * sin(-0.035 * PI);
	player->dir.y = tmp_x * sin(-0.035 * PI) + p_dir.y * cos(-0.035 * PI);
	tmp_x = player->plane.x;
	player->plane.x = plane.x * cos(-0.035 * PI) - plane.y * sin(-0.035 * PI);
	player->plane.y = tmp_x * sin(-0.035 * PI) + plane.y * cos(-0.035 * PI);
}

void	init_angle_player(t_player *player)
{
	player->angle_right = p_angle_right;
	player->angle_left = p_angle_left;
}
