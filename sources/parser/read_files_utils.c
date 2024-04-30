/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:09:40 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 15:32:38 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_coord_id(const char *line)
{
	if (ft_strncmp(line, "NO ", 2) == 0 || ft_strncmp(line, "SO ", 2) == 0
		|| ft_strncmp(line, "WE ", 2) == 0 || ft_strncmp(line, "EA ", 2) == 0)
		return (true);
	return (false);
}

bool	have_all_data(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->texture[i] == NULL)
			return (false);
		i++;
	}
	if (map->floor == NULL || map->ceiling == NULL)
		return (false);
	return (true);
}

bool	is_map(t_map *map, const char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
		{
			return (false);
		}
		if (have_all_data(map) == false)
			return (false);
		i++;
	}
	return (true);
}

int	is_empty_line(const char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \t\n\r\v\f");
	if (tmp == NULL)
		return (FAILURE);
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (true);
	}
	free(tmp);
	return (false);
}