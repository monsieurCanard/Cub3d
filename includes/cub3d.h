/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:05:28 by anthony           #+#    #+#             */
/*   Updated: 2024/05/30 13:51:07 by antgabri         ###   ########.fr       */
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

# include "cub_engine.h"

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

# define VERTICAL 1
# define HORIZONTAL 0
# define FOV 60
# define NB_TEXTURE 4

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
	t_texture	*texture[NB_TEXTURE];
}				t_data;

typedef struct s_ray
{
	float		angle;
	t_vector2	dir;
	t_vector2	delta;
	t_vector2	dist;
	t_vector2	step;
	float		step_texture_wall;
	int			index_texture;
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
///////////// GAME ///////////////////////
//////////////////////////////////////////

int			start_game(t_data *data);

int			stop_game(t_data *data);

int			init_game(t_data *data, char *path);

//////////////////////////////////////////
///////////// PLAYER /////////////////////
//////////////////////////////////////////

void		get_player(t_data *data);

t_player	*create_player(int x, int y, char direction);

//////////////////////////////////////////
///////////// EVENTS /////////////////////
//////////////////////////////////////////

int			key_release(int keycode, t_keys *keys);

int			key_press(int keycode, t_keys *keys);

int			event_player_2d(t_data *data);

void		handle_event_game(int (*hook_func)(), int event_type,
				int event_mask, t_keys *keys);

//////////////////////////////////////////
///////////// RAYCAST ////////////////////
//////////////////////////////////////////

void		raycaster(t_data *data, t_player *player);

void		init_ray(t_ray *ray, t_player *player, int x);

void		init_step(t_ray *ray, t_player *player);

void		calcul_wall(t_ray *ray, t_player *player);

t_vector2	get_coord_texture(t_ray *ray, t_data *data);

void		update_3d(t_ray *ray, t_data *data, int x);

void		debug_ray(t_vector2 start, t_vector2 end, int index);

///////////////////////////////////////////
////////////////// DRAW ///////////////////
//////////////////////////////////////////

void		draw_ceil_floor(t_map *map_data);

int			update(void *data_ptr);

//////////////////////////////////////////
//////////////// UTILS ///////////////////
//////////////////////////////////////////

float		cap_angle_rad(float angle);

//////////////////////////////////////////
///////////// ERROR / FREE ///////////////
//////////////////////////////////////////

int			print_error(char *message, int error);

void		free_map(t_map *map);

int			print_error(char *message, int error);

#endif
