/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:02:50 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 20:46:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static void	init_reload_texture(t_data *data)
{
	data->texture_player[3] = init_texture("./asset/texture/gun_reload1.xpm");
	data->texture_player[4] = init_texture("./asset/texture/gun_reload2.xpm");
	data->texture_player[5] = init_texture("./asset/texture/gun_reload3.xpm");
	data->texture_player[6] = init_texture("./asset/texture/gun_reload4.xpm");
	data->texture_player[7] = init_texture("./asset/texture/gun_reload5.xpm");
	data->texture_player[8] = init_texture("./asset/texture/gun_reload6.xpm");
	data->texture_player[9] = init_texture("./asset/texture/gun_reload7.xpm");
	data->texture_player[10] = init_texture("./asset/texture/gun_reload8.xpm");
	data->texture_player[11] = init_texture("./asset/texture/gun_reload9.xpm");
	data->texture_player[12] = init_texture("./asset/texture/gun_reload10.xpm");
	data->texture_player[13] = init_texture("./asset/texture/gun_reload11.xpm");
	data->texture_player[14] = init_texture("./asset/texture/run2.xpm");
	data->texture_player[15] = init_texture("./asset/texture/run3.xpm");
	data->texture_player[16] = init_texture("./asset/texture/run4.xpm");
	data->texture_player[17] = init_texture("./asset/texture/run5.xpm");
	data->texture_player[18] = init_texture("./asset/texture/run6.xpm");
	data->texture_player[19] = init_texture("./asset/texture/run7.xpm");
	data->texture_player[20] = init_texture("./asset/texture/run8.xpm");
	data->texture_player[21] = init_texture("./asset/texture/run9.xpm");
	data->texture_player[22] = init_texture("./asset/texture/run10.xpm");
}

static int	take_texture_player(t_data *data)
{
	int	i;

	i = 0;
	data->texture_player[0] = init_texture("./asset/texture/gun_static.xpm");
	data->texture_player[1] = init_texture("./asset/texture/gun_fire1.xpm");
	data->texture_player[2] = init_texture("./asset/texture/gun_fire2.xpm");
	init_reload_texture(data);
	while (i < NB_TEXTURE_PLAYER)
	{
		if (data->texture_player[i] == NULL)
		{
			perror("Error\n");
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

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
		stop_game(data);
		exit(print_error("failed init_window", ENOMEM));
	}
	if (take_texture_img(data->map_data->texture, data->texture) == FAILURE)
	{
		stop_game(data);
		exit(print_error("failed take_texture_img", ENOMEM));
	}
	if (take_texture_player(data) == FAILURE)
	{
		stop_game(data);
		exit(print_error("failed take_texture_player", ENOMEM));
	}
	return (SUCCESS);
}
