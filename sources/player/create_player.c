/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:14:09 by monsieurc         #+#    #+#             */
/*   Updated: 2024/06/03 19:10:17 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir = vector2(-1, 0);
		player->plane = vector2(0, -0.66);
	}
	else if (direction == 'S')
	{
		player->dir = vector2(1, 0);
		player->plane = vector2(0, 0.66);
	}
	else if (direction == 'W')
	{
		player->dir = vector2(0, 1);
		player->plane = vector2(-0.66, 0);
	}
	else if (direction == 'E')
	{
		player->dir = vector2(0, -1);
		player->plane = vector2(0.66, 0);
	}
}

t_player	*create_player(int x, int y, char direction)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		logerror(__FILE__, __LINE__, "malloc() failed");
		return (NULL);
	}
	ft_bzero(player, sizeof(t_player));
	init_move_player(player);
	get_player_direction(player, direction);
	player->pos = vector2(x + 0.5, y + 0.5);
	player->rot_speed = 0.035;
	return (player);
}
