/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/05/14 19:26:20 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static int	camera_move(int keycode, t_player *player)
{
	t_engine	*engine;
	
	engine = get_engine();
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		engine->camera->coord.y -= player->delta.y;
		engine->camera->coord.x -= player->delta.x;
		player->move_up(player);
	}
	if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		engine->camera->coord.y += player->delta.y;
		engine->camera->coord.x += player->delta.x;
		player->move_down(player);
	}
	if (keycode == KEY_RIGHT)
	{
		engine->camera->coord.x -= player->delta.y;
		engine->camera->coord.y += player->delta.x;
		player->move_right(player);
	}
	if (keycode == KEY_LEFT)
	{
		engine->camera->coord.x += player->delta.y;
		engine->camera->coord.y -= player->delta.x;
		player->move_left(player);
	}
	if (keycode == KEY_A)
	{
		player->angle_left(player);
	}
	if (keycode == KEY_D)
	{
		player->angle_right(player);
	}
	if (keycode == 65307)
	{
		stop_engine();
	}
	return (SUCCESS);
}


int	main(int ac, char **av)
{
	t_engine	*engine;
	t_data		data;

	engine = get_engine();
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
	start_game(&data);
	event_hook(&camera_move, KeyPress, KeyPressMask, data.player);
	loop(&draw_all_ray ,&data);
	return (0);
}
