/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 15:30:11 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_game(t_data *data)
{
	create_debug_map(data);
	event_hook(&event_player_2d, KeyPress, KeyPressMask, data->player, 0);
	event_hook(&event_player_2d, KeyPress, KeyPressMask, data->player, 1);
	loop(&update_game, data);
	return (SUCCESS);
}
