/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/04 11:10:45 by antgabri         ###   ########.fr       */
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

static void	update_player_move(t_player *player)
{
	handle_action(player->keys.up, player->move_up, player);
	handle_action(player->keys.down, player->move_down, player);
	handle_action(player->keys.right, player->move_right, player);
	handle_action(player->keys.left, player->move_left, player);
	if (player->keys.rot_right)
		player->rotate(player, player->rot_speed);
	if (player->keys.rot_left)
		player->rotate(player, -player->rot_speed);
}

int	event_player_2d(t_data *data)
{
	t_player	*player;
	t_vector2	old_pos;

	old_pos = data->player->pos;
	player = data->player;
	update_player_move(player);
	if (valid_move(data->player, data->map_data) == false)
	{
		player->pos = old_pos;
	}
	if (player->keys.shift != 0)
		player->speed = 5;
	else
		player->speed = 12;
	if (player->keys.open_close)
	{
		open_close_door(player, data->map_data->map);
		player->keys.open_close = 0;
	}
	if (player->keys.esc)
		stop_game(data);
	return (SUCCESS);
}
