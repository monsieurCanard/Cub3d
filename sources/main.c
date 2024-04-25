/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/04/25 18:21:06 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

int	main(int ac, char **av)
{
	// t_data	data;

	if (ac != 2)
	{
		errno = EINVAL;
		return (perror("Error"), errno);
	}
	get_map(av[1]);
	// int i = 0;
	// while (data.map_data.map[i] != NULL)
	// {
	// 	printf("%s\n", data.map_data.map[i]);
	// 	i++;
	// }
	return (0);
}