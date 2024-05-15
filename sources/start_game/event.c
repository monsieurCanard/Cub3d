/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 11:57:51 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	event_player_2d(int keycode, t_player *player)
{
	t_engine	*engine;

	engine = get_engine();
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		engine->win[player->obj->render.id_win].offset.y -= player->delta.y;
		engine->win[player->obj->render.id_win].offset.x -= player->delta.x;
		player->move_up(player);
	}
	if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		engine->win[player->obj->render.id_win].offset.y += player->delta.y;
		engine->win[player->obj->render.id_win].offset.x += player->delta.x;
		player->move_down(player);
	}
	if (keycode == KEY_RIGHT)
	{
		engine->win[player->obj->render.id_win].offset.x -= player->delta.y;
		engine->win[player->obj->render.id_win].offset.y += player->delta.x;
		player->move_right(player);
	}
	if (keycode == KEY_LEFT)
	{
		engine->win[player->obj->render.id_win].offset.x += player->delta.y;
		engine->win[player->obj->render.id_win].offset.y -= player->delta.x;
		player->move_left(player);
	}
	if (keycode == KEY_A)
	{
		player->angle_left(player);
	}
	if (keycode == KEY_D)
	{
		player->angle_right(player);
	}
	if (keycode == 65307)
	{
		stop_engine();
	}
	return (SUCCESS);
}