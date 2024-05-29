/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 10:50:02 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "core_data.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

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

bool	is_an_item(char c);

bool	valid_border(char *line);

bool	valid_condition(char **map, size_t i, size_t j);

/////////////////////////////////////////////////////////////////
////////////////////////// MAP ERROR /////////////////////////////
/////////////////////////////////////////////////////////////////

int		print_error(char *message, int error);

void	free_map(t_map *map);

#endif