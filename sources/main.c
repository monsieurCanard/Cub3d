/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/05/28 18:33:15 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

int	main(int ac, char **av)
{
	t_data		data;
	const int	event[2] = {DestroyNotify, StructureNotifyMask};

	if (ac != 2)
		exit(print_error("Wrong number of arguments", EINVAL));
	init_game(&data, av[1]);
	event_hook(stop_game, (int *)event, (void *)&data, 0);
	start_game(&data);
	return (0);
}
