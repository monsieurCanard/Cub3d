/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:15:28 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 18:23:56 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	stop_game(t_data *data)
{
	int	i;

	i = -1;
	while (++i < NB_TEXTURE)
	{
		if (!data->texture[i])
			break ;
		destroy_texture(data->texture[i]);
	}
	i = -1;
	while (++i < NB_TEXTURE_PLAYER)
	{
		if (!data->texture_player[i])
			break ;
		destroy_texture(data->texture_player[i]);
	}
	if (data->player)
		free(data->player);
	free_map(data->map_data);
	stop_engine();
	return (SUCCESS);
}

void	free_map(t_map *map)
{
	int	i;

	if (map->map)
		ft_rm_split(map->map);
	i = -1;
	while (++i < NB_TEXTURE)
	{
		if (map->texture[i])
			free(map->texture[i]);
	}
	free(map);
}
