/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:22:49 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/14 13:32:28 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	split_lst(t_list *src, t_list **front, t_list **back)
{
	t_list	*slow;
	t_list	*fast;

	slow = src;
	fast = src->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = src;
	*back = slow->next;
	slow->next = NULL;
}

static t_list	*merge_lst(t_list *lst_1, t_list *lst_2,
	int (*cmp)(void *, void *))
{
	if (lst_1 == NULL)
		return (lst_2);
	if (lst_2 == NULL)
		return (lst_1);
	if (cmp(lst_1->content, lst_2->content) < 0)
	{
		lst_1->next = merge_lst(lst_1->next, lst_2, cmp);
		return (lst_1);
	}
	else
	{
		lst_2->next = merge_lst(lst_2->next, lst_1, cmp);
		return (lst_2);
	}
}

void	ft_lstsort(t_list **head_ref, int (*cmp)(void *, void *))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *head_ref;
	if (head == NULL || head->next == NULL)
		return ;
	split_lst(head, &a, &b);
	ft_lstsort(&a, cmp);
	ft_lstsort(&b, cmp);
	*head_ref = merge_lst(a, b, cmp);
}
