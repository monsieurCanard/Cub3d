/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/05 11:43:13 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "core_data.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

# define UPPER 0
# define LOWER 1
# define LEFT 2
# define RIGHT 3

enum e_error
{
	NB_PLAYER,
	PLAYER_OUTBOUND,
	NO_PLAYER,
	NO_MAP,
	INV_OBJ,
	MAP_HOLE,
	INV_DATA,
};
/////////////////////////////////////////////////////////////////
////////////////////////// MAP PARSING //////////////////////////
/////////////////////////////////////////////////////////////////

t_map	*get_map(const char *map_name);

int		take_map(t_map *map, t_list **lst_map);

/////////////////////////////////////////////////////////////////
////////////////////////// MAP READING //////////////////////////
/////////////////////////////////////////////////////////////////

int		read_files(t_map *map, int fd_map);

int		take_colors(t_map *map, const char *line);

int		take_texture(t_map *map, const char *line);

char	**split_color(const char *line);

int		save_map_lst(t_list **list, const char *raw_line);

bool	is_coord_id(const char *line);

bool	is_map(t_map *map, const char *line);

int		is_empty_line(const char *line);

/////////////////////////////////////////////////////////////////
////////////////////////// MAP VERIFICATION /////////////////////
/////////////////////////////////////////////////////////////////

bool	have_all_data(t_map *map);

bool	is_valid_map(t_map *map_data);

bool	is_a_player(char c);

bool	valid_border(char *line);

int		valid_condition(char **map, size_t i, size_t j);

/////////////////////////////////////////////////////////////////
////////////////////////// MAP ERROR /////////////////////////////
/////////////////////////////////////////////////////////////////

int		print_error(char *message, int error);

void	free_map(t_map *map);

#endif