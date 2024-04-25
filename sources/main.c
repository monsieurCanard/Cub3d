/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/04/25 16:10:27 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		errno = EINVAL;
		return (perror("Error:"), errno);
	}
	init_mlx(&data);
	// data.map_data = open_files(av[1]);
	// int i = 0;
	// while (data.map_data.map[i] != NULL)
	// {
	// 	printf("%s\n", data.map_data.map[i]);
	// 	i++;
	// }
	return (0);
}