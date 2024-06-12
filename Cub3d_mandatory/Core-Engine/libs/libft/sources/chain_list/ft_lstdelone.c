/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:45:42 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/09 17:01:35 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **lst, t_list *node, void (*del)(void *))
{
	t_list	*prev;
	t_list	*next;

	prev = *lst;
	next = node->next;
	if (prev == node)
	{
		*lst = next;
	}
	else
	{
		while (prev->next != node)
		{
			prev = prev->next;
		}
		prev->next = next;
	}
	del(node->content);
	free(node);
}
