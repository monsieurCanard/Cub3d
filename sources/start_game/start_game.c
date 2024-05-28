/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 15:03:18 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_game(t_data *data)
{
	int	event[2];

	get_player(data);
	event[0] = KeyPress;
	event[1] = KeyPressMask;
	event_hook(&key_press, event, &(data->player->keys), 0);
	event[0] = KeyRelease;
	event[1] = KeyReleaseMask;
	event_hook(&key_release, event, &(data->player->keys), 0);
	add_loop_render(&update, data);
	loop();
	return (SUCCESS);
}
