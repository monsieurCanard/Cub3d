/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peekat_queue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:40:11 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/08 15:03:50 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_peekat_queue(t_queue *queue, size_t index)
{
	t_node		*tmp;
	size_t		i;

	i = 0;
	tmp = queue->first;
	while (tmp)
	{
		if (i == index)
			return (tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}
