/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:37:06 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/09 14:18:33 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	p_angle_right(t_player *player)
{
	player->obj->angle += 0.1;
	if (player->obj->angle > 2 * PI)
		player->obj->angle -= 2 * PI;
	player->delta.x = 5 * cos(player->obj->angle);
	player->delta.y = -(5 * sin(player->obj->angle));
}

static void	p_angle_left(t_player *player)
{
	player->obj->angle -= 0.1;
	if (player->obj->angle < 0)
		player->obj->angle += 2 * PI;
	player->delta.x = 5 * cos(player->obj->angle);
	player->delta.y = -(5 * sin(player->obj->angle));
}

void	init_angle_player(t_player *player)
{
	player->angle_right = p_angle_right;
	player->angle_left = p_angle_left;
}
