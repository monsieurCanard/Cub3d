/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:29:31 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 18:06:39 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	take_data(t_map *map, const char *raw_line)
{
	char	*line;
	int		ret;

	line = ft_strtrim(raw_line, " \t\n\r\v\f");
	if (line == NULL)
		return (FAILURE);
	if (line[0] == '\0')
	{
		free(line);
		return (SUCCESS);
	}
	if (is_coord_id(line) == true)
	{
		ret = take_texture(map, line);
		free(line);
		return (ret);
	}
	if (ft_strncmp(line, "F ", 1) == 0 || ft_strncmp(line, "C ", 1) == 0)
	{
		ret = take_colors(map, line);
		free(line);
		return (ret);
	}
	free(line);
	return (SUCCESS);
}

void	print_data(t_map *map)
{
	size_t i = 0;
	while (i < 4)
	{
		printf("texture[%zu] = %s\n", i, map->texture[i]);
		i++;
	}
	// printf("floor = %d %d %d %d\n", map->floor->a, map->floor->r, map->floor->g, map->floor->b);
	// printf("ceiling = %d %d %d %d\n", map->ceiling->a, map->ceiling->r, map->ceiling->g, map->ceiling->b);

	printf("size_x = %zu\n", map->size_x);
	printf("size_z = %zu\n", map->size_z);

	i = 0;
	while (i < map->size_z)
	{
		printf("map[%zu] = %s\n", i, map->map[i]);
		i++;
	}
}

static int	save_data(t_map *map, t_list **lst_map, const char *raw_line)
{
	if (is_map(map, raw_line) == false)
	{
		if (take_data(map, raw_line) == FAILURE)
		{
			return (FAILURE);
		}
	}
	else
	{
		if (save_map_lst(lst_map, raw_line) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static char *get_raw_line(int fd_map)
{
	char	*raw_line;
	char	*line;

	raw_line = get_next_line(fd_map);
	if (raw_line == NULL)
		return (NULL);
	line = ft_strtrim(raw_line, "\n");
	free(raw_line);
	if (line == NULL)
		return (NULL);
	return (line);
}

static int	read_file_error(t_map *map, char *raw_line)
{
	errno = print_error("Malloc failed", ENOMEM);
	if (raw_line != NULL)
		free(raw_line);
	free_map(map);
	return (FAILURE);
}
int	read_files(t_map *map, int fd_map)
{
	char	*raw_line;
	t_list	*lst_map;
	int		ret;

	lst_map = NULL;
	while (true)
	{
		raw_line = get_raw_line(fd_map);
		if (raw_line == NULL)
			break ;
		ret = is_empty_line(raw_line);
		if (ret == FAILURE)
			return (read_file_error(map, raw_line));
		else if (ret == false)
		{
			if (save_data(map, &lst_map, raw_line) == FAILURE)
				return (read_file_error(map, raw_line));
		}
		free(raw_line);
	}
	if (take_map(map, &lst_map) == FAILURE)
	{
		return (read_file_error(map, NULL));
	}
	return (SUCCESS);
}
