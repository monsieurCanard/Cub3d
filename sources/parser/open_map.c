/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:30:07 by anthony           #+#    #+#             */
/*   Updated: 2024/04/25 18:27:14 by jbrousse         ###   ########.fr       */
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
		perror("Error\n");
		exit(FAILURE);
	}
	fd = open(map_name, O_RDONLY);
	if (fd == FAILURE)
	{
		perror("Error\n");
		exit(FAILURE);
	}
	return (fd);
}

t_map	*get_map(const char *map_name)
{
	t_map	*map;
	int		fd;

	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		perror("Error\n");
		exit(FAILURE);
	}
	ft_bzero(map, sizeof(t_map));
	fd = open_files(map_name);
	read_files(map, fd);
	return (map);
}
