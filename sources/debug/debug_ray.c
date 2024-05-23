/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:02:13 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 16:06:38 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_ray(t_vector2 start, t_vector2 end, int index)
{
	t_engine	*engine;

	engine = get_engine();
	engine->debug[index]->start = world_to_screen(start, 0);
	engine->debug[index]->end = world_to_screen(end, 0);
	engine->debug[index]->color = 0x00FF00;
}
