/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/30 14:16:22 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_game(t_data *data)
{
	t_keys	*keys;

	get_player(data);
	keys = &(data->player->keys);
	handle_event_game(&key_press, KeyPress, KeyPressMask, keys);
	handle_event_game(&key_release, KeyRelease, KeyReleaseMask, keys);
	add_loop_render(&update, data);
	loop();
	return (SUCCESS);
}
