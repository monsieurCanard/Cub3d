/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/04 11:18:50 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hud.h"

int	start_game(t_data *data)
{
	t_keys	*keys;

	get_player(data);
	keys = &(data->player->keys);
	data->minimap = init_minimap(data->map_data);
	handle_event_game(&key_press, KeyPress, KeyPressMask, keys);
	handle_event_game(&key_release, KeyRelease, KeyReleaseMask, keys);
	add_loop_render(&update_render, data);
	add_loop_update(&update_logic, data);
	loop();
	return (SUCCESS);
}
