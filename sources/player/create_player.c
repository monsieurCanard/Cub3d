/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:14:09 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/25 14:20:58 by monsieurc        ###   ########.fr       */
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
	player->plane = vector2(0, -0.66);
	player->dir = vector2(-1, 0);
	player->pos = vector2(x + 0.5, y + 0.5);
	return (player);
}
