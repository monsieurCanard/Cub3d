/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:07:06 by anthony           #+#    #+#             */
/*   Updated: 2024/04/30 14:08:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <core_engine.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (init_engine() == FAILURE)
		return (EXIT_FAILURE);
	loop();
	return (0);
}
