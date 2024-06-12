/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:02:32 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 13:02:38 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

t_vector3	vector3(float x, float y, float z)
{
	t_vector3	coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}
