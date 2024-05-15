/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/05/15 13:15:28 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

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
	if (init_window(vector2(800, 800), "Cub2d") == FAILURE)
		return (EXIT_FAILURE);
	start_game(&data);
	return (0);
}
