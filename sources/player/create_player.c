/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:14:09 by monsieurc         #+#    #+#             */
/*   Updated: 2024/05/29 11:33:06 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	*create_player(int x, int y)
{
	t_player	*player;
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
