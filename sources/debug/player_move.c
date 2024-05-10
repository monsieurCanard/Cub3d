/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:35:49 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/10 17:18:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	move_up(t_player *player)
{
	player->obj->trans.pos.x += player->delta.x;
	player->obj->trans.pos.y += player->delta.y;
}

static void	move_down(t_player *player)
{
	player->obj->trans.pos.x -= player->delta.x;
	player->obj->trans.pos.y -= player->delta.y;
}

static void	move_right(t_player *player)
{
	player->obj->trans.pos.x += player->delta.y;
	player->obj->trans.pos.y -= player->delta.x;
}

static void	move_left(t_player *player)
{
	player->obj->trans.pos.x -= player->delta.y;
	player->obj->trans.pos.y += player->delta.x;
}

void	init_move_player(t_player *player)
{
	player->move_up = move_up;
	player->move_down = move_down;
	player->move_right = move_right;
	player->move_left = move_left;
	init_angle_player(player);
}
