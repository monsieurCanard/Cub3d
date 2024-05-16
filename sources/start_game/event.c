/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/16 12:59:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	event_player_2d(t_player *player)
{
	t_engine	*engine;

	engine = get_engine();
	if (player->keys.up)
	{
		engine->win[player->obj->render.id_win]->offset.y -= player->delta.y;
		engine->win[player->obj->render.id_win]->offset.x -= player->delta.x;
		player->move_up(player);
	}
	if (player->keys.down)
	{
		engine->win[player->obj->render.id_win]->offset.y += player->delta.y;
		engine->win[player->obj->render.id_win]->offset.x += player->delta.x;
		player->move_down(player);
	}
	if (player->keys.right)
	{
		engine->win[player->obj->render.id_win]->offset.x -= player->delta.y;
		engine->win[player->obj->render.id_win]->offset.y += player->delta.x;
		player->move_right(player);
	}
	if (player->keys.left)
	{
		engine->win[player->obj->render.id_win]->offset.x += player->delta.y;
		engine->win[player->obj->render.id_win]->offset.y -= player->delta.x;
		player->move_left(player);
	}
	if (player->keys.rotate_left)
	{
		player->angle_left(player);
	}
	if (player->keys.rotate_right)
	{
		player->angle_right(player);
	}
	if (player->keys.shift)
	{
		player->speed = 15;
	}
	else
	{
		player->speed = 5;
	}
	return (SUCCESS);
}