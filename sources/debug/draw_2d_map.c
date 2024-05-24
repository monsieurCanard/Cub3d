/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/24 19:32:20 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	*create_player(int x, int y)
{
	t_player	*player;
	t_debug		*debug;
	t_texture	*texture;
	int			i;

	i = 0;
	player = malloc(sizeof(t_player));
	if (!player)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	ft_bzero(player, sizeof(t_player));
	init_move_player(player);
	player->plane = vector2(0, 0.66);
	player->dir = vector2(-1, 0);
	player->pos = vector2(x + 0.5, y + 0.5);
	return (player);
}

void	get_player(t_data *data)
{
	t_engine	*engine;
	int			x;
	int			y;

	y = 0;
	while (y < (int)data->map_data->size_z)
	{
		x = 0;
		while (x < (int)data->map_data->size_x)
		{
			if (data->map_data->map[y][x] == 'N')
			{
				data->player = create_player(y, x);
			}
			x++;
		}
		y++;
	}
}
//TODO A mettre dans le parsing
