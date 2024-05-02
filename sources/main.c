/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/05/02 15:15:37 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <core_engine.h>

static int	camera_move(int keycode, t_camera *camera)
{
	t_engine	*engine;

	engine = get_engine();
	if (keycode == KEY_UP)
	{
		camera->coord->y += 12.5;
		engine->object_2d[499]->coord->y += 12.5;
	}
	else if (keycode == KEY_DOWN)
	{
		camera->coord->y -= 12.5;
		engine->object_2d[499]->coord->y -= 12.5;
	}
	else if (keycode == KEY_RIGHT)
	{
		camera->coord->x -= 12.5;
		engine->object_2d[499]->coord->x += 12.5;
	}
	else if (keycode == KEY_LEFT)
	{
		camera->coord->x += 12.5;
		engine->object_2d[499]->coord->x -= 12.5;
	}
	else if (keycode == KEY_A)
	{
		camera->angle += 0.05 * PI;
		if (camera->angle > 2 * PI)
			camera->angle = 0;
	}
	else if (keycode == KEY_D)
	{
		camera->angle -= 0.05 * PI;
		if (camera->angle < 0)
			camera->angle = 2 * PI;
	}
	else if (keycode == 65307)
	{
		stop_engine();
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_engine	*engine;


	engine = get_engine();
	if (ac != 2)
	{
		errno = EINVAL;
		perror("Error\n");
		exit(FAILURE);
	}
	map = get_map(av[1]);
	if (map == NULL)
	{
		perror("Error\n");
		exit(FAILURE);
	}
	if (init_engine() == FAILURE)
		return (EXIT_FAILURE);
	start_game(map);
	key_hook(camera_move, engine->camera);
	loop();
	return (0);
}
