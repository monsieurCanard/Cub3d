/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:37:06 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/10 17:18:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	p_angle_right(t_player *player)
{
	player->obj->trans.rot.x += 0.1;
	if (player->obj->trans.rot.x > 2 * PI)
		player->obj->trans.rot.x -= 2 * PI;
	player->delta.x = 5 * cos(player->obj->trans.rot.x);
	player->delta.y = -(5 * sin(player->obj->trans.rot.x));
}

static void	p_angle_left(t_player *player)
{
	player->obj->trans.rot.x -= 0.1;
	if (player->obj->trans.rot.x < 0)
		player->obj->trans.rot.x += 2 * PI;
	player->delta.x = 5 * cos(player->obj->trans.rot.x);
	player->delta.y = -(5 * sin(player->obj->trans.rot.x));
}

void	init_angle_player(t_player *player)
{
	player->angle_right = p_angle_right;
	player->angle_left = p_angle_left;
}
