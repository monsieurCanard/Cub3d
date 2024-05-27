/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 11:13:44 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player(t_data *data)
{
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
