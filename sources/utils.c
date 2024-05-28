/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:12:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 16:09:02 by jbrousse         ###   ########.fr       */
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

int	print_error(char *message, int error)
{
	ft_putendl_fd("Error:", 2);
	ft_putendl_fd(message, 2);
	return (error);
}
