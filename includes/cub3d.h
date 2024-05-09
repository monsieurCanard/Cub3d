/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:05:28 by anthony           #+#    #+#             */
/*   Updated: 2024/05/09 18:08:48 by antgabri         ###   ########.fr       */
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
# include <core_engine.h>

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
# include "player.h"

typedef struct s_data
{
	void		*engine;
	t_map		*map_data;
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

int		start_game(t_map *map, t_list **objs);

void	create_debug_map(t_map *map, t_list **objs);

void	print_data(t_map *map);
#endif
