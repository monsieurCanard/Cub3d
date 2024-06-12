/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:37:06 by antgabri          #+#    #+#             */
/*   Updated: 2024/06/03 19:14:51 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	rotate_player(t_player *player, float rot_speed)
{
	float		tmp_x;
	t_vector2	p_dir;
	t_vector2	plane;

	p_dir = player->dir;
	plane = player->plane;
	tmp_x = player->dir.x;
	player->dir.x = p_dir.x * cos(rot_speed * PI)
		- p_dir.y * sin(rot_speed * PI);
	player->dir.y = tmp_x * sin(rot_speed * PI)
		+ p_dir.y * cos(rot_speed * PI);
	tmp_x = player->plane.x;
	player->plane.x = plane.x * cos(rot_speed * PI)
		- plane.y * sin(rot_speed * PI);
	player->plane.y = tmp_x * sin(rot_speed * PI)
		+ plane.y * cos(rot_speed * PI);
}

void	init_angle_player(t_player *player)
{
	player->rotate = rotate_player;
}
