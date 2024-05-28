/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:58 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/28 14:48:07 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	valid_border(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

static bool	valid_condition(char **map, size_t i, size_t j)
{
	if (map[i][0] == '0')
	{
		return (false);
	}
	if (map[i][j] == ' ' && map[i][j + 1] == '0')
	{
		return (false);
	}
	else if ((map[i][j + 1] == ' ' || map[i][j + 1] == '\0')
			&& map[i][j] != '1' && map[i][j] != ' ')
	{
		return (false);
	}
	if (map[i + 1] != NULL && map[i][j] != '1'
			&& map[i][j] != ' ' && map[i + 1][j] == ' ')
	{
		return (false);
	}
	if (map[i - 1] != NULL && map[i][j] == '0'
			&& map[i - 1][j] == ' ')
	{
		return (false);
	}
	return (true);
}

static bool	is_sourrounded(t_map *map_data)
{
	size_t	i;
	size_t	j;
	char	**map;

	i = 1;
	map = map_data->map;
	if (!(valid_border(map[0])) || !(valid_border(map[map_data->size_z - 1])))
		return (false);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (valid_condition(map, i, j) == false)
			{
				printf("i = %zu, j = %zu\n", i, j);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_valid_map(t_map *map_data)
{
	size_t	i;
	size_t	j;
	size_t	nb_player;
	char	**map;

	i = 0;
	nb_player = 0;
	map = map_data->map;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				nb_player++;
			else if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	if (nb_player != 1 || is_sourrounded(map_data) == false)
		return (false);
	return (true);
}
