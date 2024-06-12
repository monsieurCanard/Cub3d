/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vector2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:40:20 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/06 14:44:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorft.h"

t_vector2	normalize_vector2(t_vector2 v)
{
	float		magnitude;
	t_vector2	result;

	magnitude = magnitude_vector2(v);
	result.x = v.x / magnitude;
	result.y = v.y / magnitude;
	return (result);
}
