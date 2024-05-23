/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/05/23 16:59:23 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static int	take_texture_img(char **file_name, t_texture **texture_tab)
{
	int			i;

	i = 0;
	while (i < 4)
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

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 2)
	{
		errno = EINVAL;
		perror("Error\n");
		exit(FAILURE);
	}
	data.map_data = get_map(av[1]);
	if (data.map_data == NULL)
	{
		perror("Error\n");
		exit(FAILURE);
	}
	if (init_engine() == FAILURE)
		return (EXIT_FAILURE);
	if (init_window(vector2(800, 800), "Cub2d") == FAILURE)
		return (EXIT_FAILURE);
	if (init_window(vector2(WIN_WIDTH, WIN_HEIGHT), "Cub3d") == FAILURE)
		return (EXIT_FAILURE);
	if (take_texture_img(data.map_data->texture, data.texture) == FAILURE)
		return (EXIT_FAILURE);
	event_hook(stop_engine, DestroyNotify, StructureNotifyMask, NULL, 0);
	event_hook(stop_engine, DestroyNotify, StructureNotifyMask, NULL, 1);
	start_game(&data);
	return (0);
}
