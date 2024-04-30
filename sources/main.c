/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/04/26 17:03:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "engine.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 2)
	{
		errno = EINVAL;
		return (perror("Error"), errno);
	}
	get_map(av[1]);
	data.engine = init_engine();
	// int i = 0;
	// while (data.map_data.map[i] != NULL)
	// {
	// 	printf("%s\n", data.map_data.map[i]);
	// 	i++;
	// }
	return (0);
}
