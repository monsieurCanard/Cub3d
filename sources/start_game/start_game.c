/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/16 11:00:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_game(t_data *data)
{
	create_debug_map(data);
	event_hook(&key_press, KeyPress, KeyPressMask, &(data->player->keys), 0);
	event_hook(&key_release, KeyRelease, KeyReleaseMask, &(data->player->keys), 0);
	event_hook(&key_press, KeyPress, KeyPressMask, &(data->player->keys), 1);
	event_hook(&key_release, KeyRelease, KeyReleaseMask, &(data->player->keys), 1);
	loop(&update_game, data);
	return (SUCCESS);
}
