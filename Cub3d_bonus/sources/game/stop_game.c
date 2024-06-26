/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:15:28 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/05 11:22:10 by Monsieur_Ca      ###   ########.fr       */
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
	if (data->minimap)
		destroy_texture(data->minimap);
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
