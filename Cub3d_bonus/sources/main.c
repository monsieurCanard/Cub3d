/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/06/05 11:58:32 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

static void	print_ctrl(void)
{
	printf(MSG);
}

int	main(int ac, char **av)
{
	t_data		data;
	const int	event[2] = {DestroyNotify, StructureNotifyMask};

	print_ctrl();
	if (ac != 2)
		exit(print_error("Wrong number of arguments", EINVAL));
	if (init_game(&data, av[1]) == FAILURE)
		exit(print_error("Failed to init game", ENOMEM));
	event_hook(stop_game, (int *)event, (void *)&data, 0);
	start_game(&data);
	return (0);
}
