/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:12:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 20:09:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	cap_angle_rad(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	else if (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}
