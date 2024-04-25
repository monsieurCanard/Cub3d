/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:29:31 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/25 18:43:12 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_coord_id(const char *line)
{
	if (ft_strncmp(line, "NO ", 2) == 0 || ft_strncmp(line, "SO ", 2) == 0
		|| ft_strncmp(line, "WE ", 2) == 0 || ft_strncmp(line, "EA ", 2) == 0)
		return (true);
	return (false);
}

static int	take_data(t_map *map, const char *line)
{
	if (line[0] == '\0')
		return (SUCCESS);
	if (is_coord_id(line) == true)
		return (take_texture(map, line));
	if (ft_strncmp(line, "F ", 1) == 0)
	{
		map->floor = take_colors(line);
		if (map->floor == NULL)
			return (FAILURE);
	}
	if (ft_strncmp(line, "C ", 1) == 0)
	{
		map->ceiling = take_colors(line);
		if (map->ceiling == NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}

static void	print_data(t_map *map)
{
	int i = 0;
	while (i < 4)
	{
		printf("texture[%d] = %s\n", i, map->texture[i]);
		i++;
	}
	printf("floor = %d %d %d %d\n", map->floor->a, map->floor->r, map->floor->g, map->floor->b);
	printf("ceiling = %d %d %d %d\n", map->ceiling->a, map->ceiling->r, map->ceiling->g, map->ceiling->b);

}


void	read_files(t_map *map, int fd_map)
{
	char	*raw_line;
	char	*line;

	while (true)
	{
		raw_line = get_next_line(fd_map);
		if (raw_line == NULL)
			break ;
		line = ft_strtrim(raw_line, " \t\n\r\v\f");
		free(raw_line);
		if (line == NULL)
			break ; // TODO stop gnl
		if (take_data(map, line) == FAILURE)
		{
			printf("data fail\n");
			free(line);
			break ; // TODO stop gnl
		}
		free(line);
	}
	print_data(map);
}
