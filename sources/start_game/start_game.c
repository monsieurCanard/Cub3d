/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:33:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/15 15:21:40 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_game(t_data *data)
{
	create_debug_map(data);
	printf("avant event_hook engine->obj2d[3] = %p\n", get_engine()->obj2d[3]);

	event_hook(&event_player_2d, KeyPress, KeyPressMask, data->player, 0);
	printf("apres event_hook engine->obj2d[3] = %p\n", get_engine()->obj2d[3]);
	
	loop(&draw_all_ray, data);
	return (SUCCESS);
}
