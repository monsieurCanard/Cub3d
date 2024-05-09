/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/05/09 18:19:40 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include <core_engine.h>

static int	camera_move(int keycode, t_list *objs)
{
	t_engine	*engine;
	t_player	*player;

	player = objs->content;
	engine = get_engine();
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		engine->camera->coord.y -= player->delta.y;
		engine->camera->coord.x -= player->delta.x;
		player->move_up(player);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		engine->camera->coord.y += player->delta.y;
		engine->camera->coord.x += player->delta.x;
		player->move_down(player);
	}
	else if (keycode == KEY_RIGHT)
	{
		engine->camera->coord.x -= player->delta.y;
		engine->camera->coord.y += player->delta.x;
		player->move_right(player);
	}
	else if (keycode == KEY_LEFT)
	{
		engine->camera->coord.x += player->delta.y;
		engine->camera->coord.y -= player->delta.x;
		player->move_left(player);
	}
	else if (keycode == KEY_A)
	{
		player->angle_left(player);
	}
	else if (keycode == KEY_D)
	{
		player->angle_right(player);
	}
	else if (keycode == 65307)
	{
		stop_engine();
	}
	draw_rays(player->obj, player->obj->coord, (t_vector2){player->obj->coord.x + 100 * cos(player->obj->angle), player->obj->coord.y - 100 * sin(player->obj->angle)});
	return (SUCCESS);
}


int	main(int ac, char **av)
{
	t_engine	*engine;
	t_list		*objs;
	t_map		*map;


	objs = NULL;
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
	start_game(map, &objs);
	event_hook(&camera_move, KeyPress, KeyPressMask, objs);
	loop(NULL ,NULL);
	return (0);
}
