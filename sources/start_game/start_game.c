/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/24 19:35:23 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_game(t_data *data)
{
	get_player(data);
	event_hook(&key_press, KeyPress, KeyPressMask, &(data->player->keys), 0);
	event_hook(&key_release, KeyRelease, KeyReleaseMask, &(data->player->keys), 0);
	loop(&update, data);
	return (SUCCESS);
}
