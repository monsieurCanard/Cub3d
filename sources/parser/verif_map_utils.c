/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:01:51 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/30 15:54:33 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_a_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	valid_border(char *line)
{
	size_t	i;

	i = 0;
	if (line == NULL)
		return (false);
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

static bool	wall_or_space(char current_pos)
{
	if (current_pos != '1' && current_pos != ' ')
		return (true);
	return (false);
}

static bool	check_around_pos(char current_pos, char *around)
{
	if ((around[LEFT] == ' ' || around[RIGHT] == ' ')
		&& (wall_or_space(current_pos)) == true)
		return (false);
	if ((around[UPPER] == ' ' || around[LOWER] == ' ')
		&& (wall_or_space(current_pos)) == true)
		return (false);
	return (true);
}

bool	valid_condition(char **map, size_t i, size_t j)
{
	char	around[4];
	char	current;

	current = map[i][j];
	if (current != '1' && current != '0'
		&& current != ' ' && !(is_a_player(current)) && current != 'P')
		return (false);
	if (map[i - 1] && map[i - 1][j] != '\0')
		around[UPPER] = map[i - 1][j];
	else
		around[UPPER] = ' ';
	if (map[i + 1] && map[i + 1][j] != '\0')
		around[LOWER] = map[i + 1][j];
	else
		around[LOWER] = ' ';
	if (j >= 1 && map[i][j - 1] != '\0')
		around[LEFT] = map[i][j - 1];
	else
		around[LEFT] = ' ';
	if (map[i][j + 1] != '\0')
		around[RIGHT] = map[i][j + 1];
	else
		around[RIGHT] = ' ';
	return (check_around_pos(map[i][j], around));
}
