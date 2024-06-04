/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:48:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 13:57:32 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "cub_engine.h"
# include "cub3d.h"

# define SIZE_MINIMAP 150
# define BORDER_SIZE_MP 5
# define OFFSET_MINIMAP 35
# define SIZE_PLAYER_MP 8
# define RAD_SQR_PLAYER 16
# define SIZE_SQUARE 15

t_texture	*init_minimap(t_map *map);

void		update_hud(t_data *data);

void		update_minimap(t_texture *minimap, t_player *player);

#endif