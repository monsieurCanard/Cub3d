/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:08 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 15:27:43 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "core_data.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

int		take_colors(t_map *map, const char *line);

int		take_texture(t_map *map, const char *line);

void	read_files(t_map *map, int fd_map);

t_map	*get_map(const char *map_name);

char	**split_color(const char *line);

int		save_map_lst(t_list **list, const char *raw_line);

int		take_map(t_map *map, t_list **lst_map);

bool	is_coord_id(const char *line);

bool	have_all_data(t_map *map);

bool	is_map(t_map *map, const char *line);

int		is_empty_line(const char *line);

#endif