/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:15:53 by monsieurc         #+#    #+#             */
/*   Updated: 2024/06/03 18:21:46 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	run_animation(t_data *data)
{
	static int	iter;

	if (data->player->keys.shift == 14)
		iter = 1;
	data->player->keys.shift += iter;
	if (data->player->keys.shift == 22)
		iter = -1;
	draw_texture_player(data->texture_player[data->player->keys.shift]);
}

void	update_player(t_data *data)
{
	if (data->player->keys.fire > 0)
	{
		draw_texture_player(data->texture_player[data->player->keys.fire]);
		data->player->keys.fire--;
	}
	else if (data->player->keys.reload > 2)
	{
		draw_texture_player(data->texture_player[data->player->keys.reload]);
		usleep(950);
		data->player->keys.reload--;
	}
	else
	{
		if (data->player->keys.shift != 0)
			run_animation(data);
		else
			draw_texture_player(data->texture_player[0]);
	}
}
