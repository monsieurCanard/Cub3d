/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:37:06 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/27 10:07:27 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

// void	cal_delta(t_player *player)
// {
// 	player->delta.x = player->speed * cos(player->rot.x);
// 	player->delta.y = -(player->speed * sin(player->rot.x));
// }

static void	p_angle_right(t_player *player)
{
	float	tmp_x;

	tmp_x = player->dir.x;
	player->dir.x = player->dir.x * cos(0.035 * PI) - player->dir.y * sin(0.035 * PI);
	player->dir.y = tmp_x * sin(0.035 * PI) + player->dir.y * cos(0.035 * PI);
	tmp_x = player->plane.x;
	player->plane.x = player->plane.x * cos(0.035 * PI) - player->plane.y * sin(0.035 * PI);
	player->plane.y = tmp_x * sin(0.035 * PI) + player->plane.y * cos(0.035 * PI);
}

static void	p_angle_left(t_player *player)
{
	float	tmp_x;
	
	tmp_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-0.035 * PI) - player->dir.y * sin(-0.035 * PI);
	player->dir.y = tmp_x * sin(-0.035 * PI) + player->dir.y * cos(-0.035 * PI);
	tmp_x = player->plane.x;
	player->plane.x = player->plane.x * cos(-0.035 * PI) - player->plane.y * sin(-0.035 * PI);
	player->plane.y = tmp_x * sin(-0.035 * PI) + player->plane.y * cos(-0.035 * PI);
}

void	init_angle_player(t_player *player)
{
	player->angle_right = p_angle_right;
	player->angle_left = p_angle_left;
}
