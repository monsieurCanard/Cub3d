/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:35:49 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/25 10:52:36 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	move_up(t_player *player)
{
	// cal_delta(player);
	player->pos.x += player->dir.x / 4;
	player->pos.y += player->dir.y / 4;
}

static void	move_down(t_player *player)
{
	// cal_delta(player);
	player->pos.x -= player->dir.x / 4;
	player->pos.y -= player->dir.y / 4;
}

static void	move_left(t_player *player)
{
	// cal_dir(player);
	player->pos.x += player->dir.y / 4;
	player->pos.y -= player->dir.x / 4;
}

static void	move_right(t_player *player)
{
	// cal_dir(player);
	player->pos.x -= player->dir.y / 4;
	player->pos.y += player->dir.x / 4;
}

void	init_move_player(t_player *player)
{
	player->move_up = move_up;
	player->move_down = move_down;
	player->move_right = move_right;
	player->move_left = move_left;
	init_angle_player(player);
}
