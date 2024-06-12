/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:34:15 by antgabri          #+#    #+#             */
/*   Updated: 2024/06/04 13:46:43 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_close_door(t_player *player, char **map)
{
	t_vector2	futur_pos;

	futur_pos.x = player->pos.x + player->dir.x;
	futur_pos.y = player->pos.y + player->dir.y;
	if (map[(int)futur_pos.x] == NULL)
		return ;
	if (futur_pos.y >= ft_strlen(map[(int)futur_pos.x]))
		return ;
	if (map[(int)futur_pos.x][(int)(futur_pos.y)] == 'P')
	{
		map[(int)futur_pos.x][(int)(futur_pos.y)] = 'O';
	}
	else if (map[(int)(futur_pos.x)][(int)(futur_pos.y)] == 'O')
	{
		map[(int)futur_pos.x][(int)(futur_pos.y)] = 'P';
	}
}

static bool	out_of_boundaries(t_vector2 futur_pos, t_map *map_data)
{
	t_vector2	size;

	size.x = 0;
	if (futur_pos.x < map_data->size_z)
		size.x = ft_strlen(map_data->map[(int)futur_pos.x]);
	if (futur_pos.y >= size.x)
		return (true);
	if ((int)futur_pos.x < 0 || (int)futur_pos.y < 0)
		return (true);
	return (false);
}

static bool	valid_move_x(t_player *player, t_map *map_data, float dx)
{
	t_vector2	futur_pos;
	char		**map;
	float		i;
	float		j;

	futur_pos = player->pos;
	map = map_data->map;
	i = -0.2;
	while (i <= 0.2)
	{
		j = -0.2;
		while (j <= 0.2)
		{
			futur_pos.x = player->pos.x + dx + i;
			futur_pos.y = player->pos.y + j;
			if (out_of_boundaries(futur_pos, map_data) == true)
				return (false);
			if (is_a_wall(map[(int)futur_pos.x][(int)(futur_pos.y)]) == true)
				return (false);
			j += 0.2;
		}
		i += 0.2;
	}
	return (true);
}

static bool	valid_move_y(t_player *player, t_map *map_data, float dy)
{
	t_vector2	futur_pos;
	char		**map;
	t_vector2	iter;

	futur_pos = player->pos;
	map = map_data->map;
	iter.x = -0.2;
	while (iter.x <= 0.2)
	{
		iter.y = -0.2;
		while (iter.y <= 0.2)
		{
			futur_pos.x = player->pos.x + iter.x;
			futur_pos.y = player->pos.y + dy + iter.y;
			if (out_of_boundaries(futur_pos, map_data) == true)
				return (false);
			if (is_a_wall(map[(int)futur_pos.x][(int)(futur_pos.y)] == true))
				return (false);
			iter.y += 0.2;
		}
		iter.x += 0.2;
	}
	return (true);
}

bool	valid_move(t_player *player, t_map *map_data)
{
	if (valid_move_x(player, map_data, 0) == false)
		return (false);
	if (valid_move_y(player, map_data, 0) == false)
		return (false);
	if (valid_move_x(player, map_data, player->dir.x / player->speed) == false)
		return (false);
	if (valid_move_y(player, map_data, player->dir.y / player->speed) == false)
		return (false);
	return (true);
}
