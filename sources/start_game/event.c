/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 14:36:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	event_player_2d(t_player *player)
{
	t_engine	*engine;

	engine = __get_engine();
	if (player->keys.up)
	{
		player->move_up(player);
	}
	if (player->keys.down)
	{
		player->move_down(player);
	}
	if (player->keys.right)
	{
		player->move_right(player);
	}
	if (player->keys.left)
	{
		player->move_left(player);
	}
	if (player->keys.rot_left)
	{
		player->angle_left(player);
	}
	if (player->keys.rot_right)
	{
		player->angle_right(player);
	}
	if (player->keys.shift)
	{
		player->speed = 5;
	}
	else
	{
		player->speed = 12;
	}
	return (SUCCESS);
}
