/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/04/26 14:17:05 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 2)
	{
		errno = EINVAL;
		return (perror("Error:"), errno);
	}
	init_mlx(&data);
	start_game(&data);
	return (0);
}
