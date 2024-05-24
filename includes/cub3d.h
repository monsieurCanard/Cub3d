/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:05:28 by anthony           #+#    #+#             */
/*   Updated: 2024/05/24 19:32:35 by jbrousse         ###   ########.fr       */
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

# define WIN_WIDTH 1080
# define WIN_HEIGHT 1080

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
	t_texture	*texture[4];
}				t_data;

typedef struct s_ray
{
	float		angle;
	t_vector2	dir;
	t_vector2	delta;
	t_vector2	dist;
	t_vector2	step;
	float		line_height;
	float		draw_start;
	float		draw_end;
	float		wall_dist;
	float		wall_x;
	int			map_x;
	int			map_y;
	int			hit_axis;
}				t_ray;

//////////////////////////////////////////
///////////// EVENTS /////////////////////
//////////////////////////////////////////

// t_map		open_files(char *map_name);

//////////////////////////////////////////
//////////////// UTILS ///////////////////
//////////////////////////////////////////

float		cap_angle_rad(float angle);

//////////////////////////////////////////
///////////// GAME ///////////////////////
//////////////////////////////////////////

int			start_game(t_data *data);

// void		create_debug_map(t_data *data);

void		print_data(t_map *map);

//////////////////////////////////////////
///////////// RAYCAST ////////////////////
//////////////////////////////////////////

int			event_player_2d(t_player *player);

// float		get_ray(t_data *data, float angle, int index, t_vector2 *coord_ray);

t_vector2	cast_ray(float angle, t_data *data, int *hit_axis, int index);

t_vector2	cast_ray_v(t_map *map, t_vector2 start, float angle);

t_vector2	cast_ray_h(t_map *map, t_vector2 start, float angle);

//////////////////////////////////////////
////////////////// 3D ////////////////////
//////////////////////////////////////////

void		draw_ceil_floor(t_map *map_data);

int			update(void *data_ptr);

void		debug_ray(t_vector2 start, t_vector2 end, int index);

void		get_player(t_data *data);


#endif
