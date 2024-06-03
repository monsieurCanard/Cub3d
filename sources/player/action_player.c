/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:34:15 by antgabri          #+#    #+#             */
/*   Updated: 2024/06/03 12:37:42 by antgabri         ###   ########.fr       */
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

bool	valid_move(t_player *player, t_map *map_data)
{
	t_vector2	futur_pos;
	char		**map;

	futur_pos = player->pos;
	map = map_data->map;
	if (out_of_boundaries(futur_pos, map_data) == true)
		return (false);
	if (map[(int)futur_pos.x][(int)(futur_pos.y)] == '1' ||
		map[(int)futur_pos.x][(int)(futur_pos.y)] == 'P')
	{
		return (false);
	}
	return (true);
}
