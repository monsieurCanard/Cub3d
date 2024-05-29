/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:58 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/29 15:14:41 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	is_sourrounded(t_map *map_data, int *nb_player)
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
				return (false);
			if (is_a_player(map_data->map[i][j]) == true)
				*nb_player += 1;
			j++;
		}
		i++;
	}
	return (true);
}

static bool	error_map(int error_nb)
{
	if (error_nb == 1)
		errno = print_error("Map Invalid", EINVAL);
	else if (error_nb == 2)
		errno = print_error("Wrong Number of Player", EINVAL);
	return (false);
}

bool	is_valid_map(t_map *map_data)
{
	int		ret;
	int		nb_player;

	nb_player = 0;
	ret = is_sourrounded(map_data, &nb_player);
	if (ret == false)
		return (error_map(1));
	else if (nb_player != 1)
		return (error_map(2));
	return (true);
}
