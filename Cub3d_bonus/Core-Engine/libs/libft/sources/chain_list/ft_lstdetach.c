/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdetach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:15:52 by jbrousse          #+#    #+#             */
/*   Updated: 2024/03/30 17:17:13 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstdetach(t_list **lst, t_list *current_index)
{
	t_list	*prev;
	t_list	*next;

	prev = *lst;
	next = current_index->next;
	if (prev == current_index)
	{
		*lst = next;
	}
	else
	{
		while (prev->next != current_index)
		{
			prev = prev->next;
		}
		prev->next = next;
	}
	return (current_index);
}
