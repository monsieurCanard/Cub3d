/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:43:02 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/04 11:18:28 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	norm_rot(int x, t_win *win)
{
	float	rot;

	rot = (float)x / (float)win->width;
	return (rot);
}

void	mouse_rot(t_player *player)
{
	int		x;
	int		y;
	int		x_win;
	int		y_win;
	int		center_x;

	get_mouse_pos_hook(0, &x, &y);
	get_pos_win(&x_win, &y_win);
	center_x = (x - x_win) - __get_engine()->win[0]->width / 2;
	if (center_x != 0)
	{
		player->rotate(player, norm_rot(center_x, __get_engine()->win[0]));
		fix_pointer(x_win + __get_engine()->win[0]->width / 2,
			y_win + __get_engine()->win[0]->height / 2);
	}
}
