/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:02:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/30 15:59:17 by antgabri         ###   ########.fr       */
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
		printf("file_name[%d] = %s\n", i, file_name[i]);
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
		stop_game(data);
		exit(print_error("failed init_window", ENOMEM));
	}
	if (take_texture_img(data->map_data->texture, data->texture) == FAILURE)
	{
		stop_game(data);
		exit(print_error("failed take_texture_img", ENOMEM));
	}
	return (SUCCESS);
}
