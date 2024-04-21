/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/04/20 17:53:37 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		errno = EINVAL;
		return (perror("Error:"), errno);
	}
	data.map_data = open_files(av[1]);
	int i = 0;
	while (data.map_data.map[i] != NULL)
	{
		printf("%s\n", data.map_data.map[i]);
		i++;
	}
	return (0);
}