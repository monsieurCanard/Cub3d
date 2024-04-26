/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:04:31 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 15:29:43 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	save_map_lst(t_list **list, const char *raw_line)
{
	t_list			*new;
	char			*line;

	line = ft_strdup(raw_line);
	if (line == NULL)
		return (FAILURE);
	new = ft_lstnew(line);
	if (new == NULL)
	{
		free(line);
		return (FAILURE);
	}
	ft_lstadd_back(list, new);
	return (SUCCESS);
}

static size_t	get_max_x(t_list *lst_map)
{
	size_t	max_z;
	size_t	len;

	max_z = 0;
	while (lst_map)
	{
		len = ft_strlen(lst_map->content);
		if (len > max_z)
			max_z = len;
		lst_map = lst_map->next;
	}
	return (max_z);
}

static size_t	get_max_z(t_list *lst_map)
{
	return (ft_lstsize(lst_map));
}

int	take_map(t_map *map, t_list **lst_map)
{
	t_list	*iterator;
	size_t	i;

	map->size_x = get_max_x(*lst_map);
	map->size_z = get_max_z(*lst_map);
	map->map = ft_calloc(map->size_z + 1, sizeof(char *));
	if (map->map == NULL)
		return (FAILURE);
	iterator = *lst_map;
	i = 0;
	while (iterator)
	{
		map->map[i] = ft_calloc(map->size_x + 1, sizeof(char));
		if (map->map[i] == NULL)
			return (FAILURE);
		ft_memset(map->map[i], ' ', sizeof(map->size_x));
		ft_memcpy(map->map[i], iterator->content, ft_strlen(iterator->content));
		iterator = iterator->next;
		i++;
	}
	ft_lstclear(lst_map, free);
	return (SUCCESS);
}
