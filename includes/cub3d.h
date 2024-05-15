/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:05:28 by anthony           #+#    #+#             */
/*   Updated: 2024/05/15 11:58:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <libft.h>
# include <core.h>

# define FAILURE -1
# define SUCCESS 0

# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define PI 3.14159265359
# define DR 0.01745329251

# define FLOOR 0
# define WALL 1
# define PLAYER 2

# define FOV 60

//////////////////////////////////////
///////////// DEBUG //////////////////
//////////////////////////////////////

# define FULL_SQUARE "./debug/full_debug_square.xpm"
# define EMPTY_SQUARE "./debug/empty_debug_square.xpm"

//MAIN

# include "core_data.h"
# include "player.h"

typedef struct s_data
{
	t_map		*map_data;
	t_player	*player;
}				t_data;

//////////////////////////////////////////
///////////// EVENTS /////////////////////
//////////////////////////////////////////

// t_map		open_files(char *map_name);

//////////////////////////////////////////
///////////// PLAYER /////////////////////
//////////////////////////////////////////

//////////////////////////////////////////
///////////// GAME ///////////////////////
//////////////////////////////////////////

int		start_game(t_data *data);

void	create_debug_map(t_data *data);

void	print_data(t_map *map);

void 	draw_all_ray(void *obj);

int	event_player_2d(int keycode, t_player *player);


t_vector2	cast_ray_v(t_map *map, t_vector2 start, float angle);

#endif
