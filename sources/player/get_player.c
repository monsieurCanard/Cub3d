/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:18:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 11:59:42 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

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
			if (is_a_player(data->map_data->map[y][x]) == true)
			{
				data->player = create_player(y, x, data->map_data->map[y][x]);
			}
			x++;
		}
		y++;
	}
}
