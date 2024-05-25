/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:38:53 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/25 09:06:20 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector2	cast_ray(float angle, t_data *data, int *hit_axis, int index)
{
	t_vector2		end_h;
	t_vector2		end_v;
	t_vector2		player_pos;

	player_pos = data->player->pos;
	end_h = cast_ray_h(data->map_data, player_pos, angle);
	end_v = cast_ray_v(data->map_data, player_pos, angle);
	if (magnitude_vector2(sub_vector2(end_h, player_pos))
		< magnitude_vector2(sub_vector2(end_v, player_pos)))
	{
		*hit_axis = 0;
		debug_ray(player_pos, end_h, index);
		return (end_h);
	}
	else
	{
		*hit_axis = 1;
		debug_ray(player_pos, end_v, index);
		return (end_v);
	}
}
