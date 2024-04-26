/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:39:01 by antgabri          #+#    #+#             */
/*   Updated: 2024/04/26 17:07:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	key_press(int keycode, t_engine *engine)
{
	if (keycode == ESCAPE)
	{
		close_window(engine);
		exit(0);
	}
	// if (keycode == LEFT)
	// {
	// 	data->player.x -= 10;
	// }
	// if (keycode == RIGHT)
	// {
	// 	data->player.x += 10;
	// }
	// if (keycode == UP)
	// {
	// 	data->player.y += 10;
	// }
	// if (keycode == DOWN)
	// {
	// 	data->player.y -= 10;
	// }
	// create_game(data);
	return (0);
}
