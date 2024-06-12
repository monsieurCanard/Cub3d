/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:33:10 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/06 14:45:09 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

t_vector3	add_vector3(t_vector3 v, t_vector3 w)
{
	t_vector3	result;

	result.x = v.x + w.x;
	result.y = v.y + w.y;
	result.z = v.z + w.z;
	return (result);
}
