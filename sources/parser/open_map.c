/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:30:07 by anthony           #+#    #+#             */
/*   Updated: 2024/05/28 18:06:31 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parser.h"

bool	check_extension(const char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4)
	{
		errno = EINVAL;
		return (false);
	}
	if (ft_strncmp(&map_name[len - 4], ".cub", 4) != 0)
	{
		errno = EINVAL;
		return (false);
	}
	return (true);
}

int	open_files(const char *map_name)
{
	int	fd;

	if (check_extension(map_name) == false)
	{
		errno = print_error("Invalid file extension", EINVAL);
		return (FAILURE);
	}
	fd = open(map_name, O_RDONLY);
	if (fd == FAILURE)
	{
		errno = print_error("Failed to open file", errno);
		return (FAILURE);
	}
	return (fd);
}

t_map	*get_map(const char *map_name)
{
	t_map	*map;
	int		fd;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		exit(print_error("Malloc failed", ENOMEM));
	fd = open_files(map_name);
	if (fd == FAILURE)
	{
		free(map);
		exit(errno);
	}
	if (read_files(map, fd) == FAILURE)
	{
		close(fd);
		free(map);
		exit(errno);
	}
	if (is_valid_map(map) == false)
	{
		ft_rm_split(map->map);
		free(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}
