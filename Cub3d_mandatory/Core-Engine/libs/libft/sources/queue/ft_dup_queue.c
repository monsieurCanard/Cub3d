/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:51:53 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/08 14:33:22 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_dup_queue(t_queue *queue, void *(*dup_content)(void *content))
{
	t_node	*tmp;
	t_queue	*new_queue;
	void	*content;

	tmp = queue->first;
	new_queue = ft_init_queue();
	if (!new_queue)
		return (NULL);
	while (tmp)
	{
		content = dup_content(tmp->content);
		ft_enqueue(new_queue, content);
		tmp = tmp->next;
	}
	return (new_queue);
}
