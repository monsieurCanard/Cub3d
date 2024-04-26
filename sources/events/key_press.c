/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:39:01 by antgabri          #+#    #+#             */
/*   Updated: 2024/04/26 14:17:24 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		close_window(data);
		exit(0);
	}
	if (keycode == LEFT)
	{
		data->player.x -= 10;
	}
	if (keycode == RIGHT)
	{
		data->player.x += 10;
	}
	if (keycode == UP)
	{
		data->player.y += 10;
	}
	if (keycode == DOWN)
	{
		data->player.y -= 10;
	}
	create_game(data);
	return (0);
}
