/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:01:51 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/29 11:54:02 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_a_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	is_an_item(char c)
{
	if (c != '1' && c != '0' && c != ' ' && is_a_player(c) == false)
		return (false);
	return (true);
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

bool	valid_condition(char **map, size_t i, size_t j)
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
