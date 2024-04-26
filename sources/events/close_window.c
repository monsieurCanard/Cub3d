/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:39:56 by antgabri          #+#    #+#             */
/*   Updated: 2024/04/26 17:08:02 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	close_window(t_engine *engine)
{
	mlx_destroy_window(engine->mlx_ptr, engine->win_ptr);
	mlx_destroy_image(engine->mlx_ptr, engine->e_void.img_ptr);
	mlx_destroy_display(engine->mlx_ptr);
	free (engine->mlx_ptr);
	exit (EXIT_SUCCESS);
}
