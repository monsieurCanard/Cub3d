/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:35:49 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/31 11:20:45 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	move_up(t_player *player)
{
	player->pos.x += player->dir.x / player->speed;
	player->pos.y -= player->dir.y / player->speed;
}

static void	move_down(t_player *player)
{
	player->pos.x -= player->dir.x / player->speed;
	player->pos.y += player->dir.y / player->speed;
}

static void	move_left(t_player *player)
{
	player->pos.x -= player->dir.y / player->speed;
	player->pos.y -= player->dir.x / player->speed;
}

static void	move_right(t_player *player)
{
	player->pos.x += player->dir.y / player->speed;
	player->pos.y += player->dir.x / player->speed;
}

void	init_move_player(t_player *player)
{
	player->move_up = move_up;
	player->move_down = move_down;
	player->move_right = move_right;
	player->move_left = move_left;
	init_angle_player(player);
}
