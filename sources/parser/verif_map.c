/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:58 by antgabri          #+#    #+#             */
/*   Updated: 2024/06/04 13:24:20 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_sourrounded(t_map *map_data, int *nb_player)
{
	size_t	i;
	size_t	j;
	int		ret;
	char	**map;

	i = 1;
	map = map_data->map;
	if (!(valid_border(map[0])) || !(valid_border(map[map_data->size_z - 1])))
		return (MAP_HOLE);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			ret = valid_condition(map, i, j);
			if (ret != SUCCESS)
				return (ret);
			if (is_a_player(map_data->map[i][j]) == true)
				*nb_player += 1;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static bool	error_map(int error_nb)
{
	if (error_nb == NB_PLAYER)
		errno = print_error("Wrong Number of Player", EINVAL);
	else if (error_nb == PLAYER_OUTBOUND)
		errno = print_error("Player out of boundaries", EINVAL);
	else if (error_nb == INV_OBJ)
		errno = print_error("Invalid object in map", EINVAL);
	else if (error_nb == MAP_HOLE)
		errno = print_error("Map not sourrounded by walls", EINVAL);
	return (false);
}

bool	is_valid_map(t_map *map_data)
{
	int		ret;
	int		nb_player;

	nb_player = 0;
	ret = is_sourrounded(map_data, &nb_player);
	if (ret != SUCCESS)
		return (error_map(ret));
	else if (nb_player != 1)
		return (error_map(NB_PLAYER));
	return (true);
}
