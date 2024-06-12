/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:12:44 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/04 11:02:28 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *message, int error)
{
	ft_putendl_fd("Error:", 2);
	ft_putendl_fd(message, 2);
	return (error);
}

float	cap_angle(float angle)
{
	if (angle < -PI)
		angle += 2 * PI;
	if (angle > PI)
		angle -= 2 * PI;
	return (angle);
}

bool	is_a_wall(char c)
{
	if (c == '1' || c == 'P')
		return (true);
	return (false);
}
