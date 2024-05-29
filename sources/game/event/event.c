/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 13:53:10 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_event_game(int (*hook_func)(), int event_type,
	int event_mask, t_keys *keys)
{
	int	event[2];

	event[0] = event_type;
	event[1] = event_mask;
	event_hook(hook_func, event, keys, 0);
}

static void	handle_action(int press, void (*action)(t_player *), t_player *p)
{
	if (press)
	{
		action(p);
	}
}

int	event_player_2d(t_data *data)
{
	t_player	*player;

	player = data->player;
	handle_action(player->keys.up, player->move_up, player);
	handle_action(player->keys.down, player->move_down, player);
	handle_action(player->keys.right, player->move_right, player);
	handle_action(player->keys.left, player->move_left, player);
	handle_action(player->keys.rot_left, player->angle_left, player);
	handle_action(player->keys.rot_right, player->angle_right, player);
	if (player->keys.shift)
		player->speed = 5;
	else
	{
		player->speed = 12;
	}
	if (player->keys.esc)
	{
		stop_game(data);
	}
	return (SUCCESS);
}
