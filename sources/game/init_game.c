/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monsieurc <monsieurc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:02:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 13:49:20 by monsieurc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static int	take_texture_img(char **file_name, t_texture **texture_tab)
{
	int			i;

	i = 0;
	while (i < NB_TEXTURE)
	{
		texture_tab[i] = init_texture(file_name[i]);
		if (texture_tab[i] == NULL)
		{
			perror("Error\n");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	init_game(t_data *data, char *path)
{
	ft_bzero(data, sizeof(t_data));
	data->map_data = get_map(path);
	if (init_engine() == FAILURE)
	{
		free_map(data->map_data);
		exit(print_error("failed init_engine", ENOMEM));
	}
	if (init_window(vector2(WIN_WIDTH, WIN_HEIGHT), "Cub3d") == FAILURE)
	{
		stop_engine();
		free_map(data->map_data);
		exit(print_error("failed init_window", ENOMEM));
	}
	if (take_texture_img(data->map_data->texture, data->texture) == FAILURE)
		return (EXIT_FAILURE);
	return (SUCCESS);
}
