/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/30 17:23:28 by antgabri         ###   ########.fr       */
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

static bool	valid_move(t_player *player, char **map)
{
	t_vector2	futur_pos;
	t_vector2	step;

	printf("player->dir.x = %f\n", player->dir.x);
	printf("player->dir.y = %f\n", player->dir.y);
	if (player->dir.x > 0)
		step.x = 0.2;
	else
		step.x = -0.2;
	if (player->dir.y < 0)
		step.y = 0.2;
	else
		step.y = -0.2;
	futur_pos.x = (player->pos.x + step.x);
	futur_pos.y = (player->pos.y + step.y);
	if (map[(int)futur_pos.x][(int)(futur_pos.y)] == '1' ||
		map[(int)futur_pos.x][(int)(futur_pos.y)] == 'P')
	{
		return (false);
	}
	return (true);
}

static void	open_close_door(t_player *player, char **map)
{
	t_vector2	futur_pos;

	futur_pos.x = player->pos.x + player->dir.x;
	futur_pos.y = player->pos.y + player->dir.y;
	printf("futur_pos.x = %d\n", (int)futur_pos.x);
	printf("futur_pos.y = %d\n", (int)futur_pos.y);
	printf("map[(int)futur_pos.x][(int)(futur_pos.y)] = %c\n", map[(int)futur_pos.x][(int)(futur_pos.y)]);
	if (map[(int)futur_pos.x][(int)(futur_pos.y)] == 'P')
	{
		map[(int)futur_pos.x][(int)(futur_pos.y)] = 'C';
	}
	else if (map[(int)(futur_pos.x)][(int)(futur_pos.y)] == 'C')
	{
		map[(int)futur_pos.x][(int)(futur_pos.y)] = 'P';
	}
}

int	event_player_2d(t_data *data)
{
	t_player	*player;
	t_vector2	pos;

	pos = data->player->pos;
	player = data->player;
	handle_action(player->keys.up, player->move_up, player);
	handle_action(player->keys.down, player->move_down, player);
	handle_action(player->keys.right, player->move_right, player);
	handle_action(player->keys.left, player->move_left, player);
	handle_action(player->keys.rot_left, player->angle_left, player);
	handle_action(player->keys.rot_right, player->angle_right, player);
	if (valid_move(player, data->map_data->map) == false)
	{
		player->pos = pos;
	}
	if (player->keys.shift)
		player->speed = 5;
	else
		player->speed = 12;
	if (player->keys.open_close)
	{
		open_close_door(player, data->map_data->map);
		player->keys.open_close = 0;
	}
	if (player->keys.esc)
	{
		stop_game(data);
	}
	return (SUCCESS);
}
