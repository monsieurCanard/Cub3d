/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_vector2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:40:22 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/06 14:46:00 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

t_vector2	sub_vector2(t_vector2 v, t_vector2 w)
{
	t_vector2	result;

	result.x = v.x - w.x;
	result.y = v.y - w.y;
	return (result);
}
