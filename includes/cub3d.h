/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:05:28 by anthony           #+#    #+#             */
/*   Updated: 2024/04/26 22:10:56 by jbrousse         ###   ########.fr       */
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
# include "libft.h"
# include "mlx.h"

# define FAILURE -1
# define SUCCESS 0


# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define PI 3.14159265359

//////////////////////////////////////
///////////// DEBUG //////////////////
//////////////////////////////////////

# define FULL_SQUARE "./debug/full_debug_square.xpm"
# define EMPTY_SQUARE "./debug/empty_debug_square.xpm"

//MAIN

# include "core_data.h"



typedef struct s_player
{
	float	x;
	float	y;
}				t_player;

typedef struct s_data
{
	void		*engine;
	t_player	player;
	t_map		*map_data;
}				t_data;



//////////////////////////////////////////
///////////// EVENTS /////////////////////
//////////////////////////////////////////

// t_map		open_files(char *map_name);

//////////////////////////////////////////
///////////// PLAYER /////////////////////
//////////////////////////////////////////
void		create_player(t_data *data);

//////////////////////////////////////////
///////////// GAME ///////////////////////
//////////////////////////////////////////

void		create_game(t_data *data);
void		start_game(t_data *data);

void	draw_2d_map(void *engine, t_map *map);

#endif
