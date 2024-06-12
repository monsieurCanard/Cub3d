/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:01:51 by antgabri          #+#    #+#             */
/*   Updated: 2024/06/04 17:21:19 by Monsieur_Ca      ###   ########.fr       */
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

static int	check_around_pos(char current_pos, char *around)
{
	if ((around[LEFT] == ' ' || around[RIGHT] == ' ')
		&& (wall_or_space(current_pos)) == true)
	{
		if (is_a_player(current_pos))
			return (PLAYER_OUTBOUND);
		else
			return (MAP_HOLE);
	}
	if ((around[UPPER] == ' ' || around[LOWER] == ' ')
		&& (wall_or_space(current_pos)) == true)
	{
		if (is_a_player(current_pos))
			return (PLAYER_OUTBOUND);
		else
			return (MAP_HOLE);
	}
	return (SUCCESS);
}

int	valid_condition(char **map, size_t i, size_t j)
{
	char	around[4];
	char	current;

	current = map[i][j];
	if (current != '1' && current != '0' && current != ' '
		&& !(is_a_player(current)))
		return (INV_OBJ);
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
