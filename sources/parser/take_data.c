/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:04:21 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 21:15:31 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_argb	*hook_color(const char *line)
{
	t_argb	*color;
	char	**colors;

	color = ft_calloc(1, sizeof(t_argb));
	if (color == NULL)
		return (NULL);
	colors = split_color(line);
	if (colors == NULL)
	{
		free(color);
		return (NULL);
	}
	color->a = 255;
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);
	ft_rm_split(colors);
	return (color);
}

int	take_colors(t_map *map, const char *line)
{
	if (ft_strncmp(line, "F ", 1) == 0)
	{
		map->floor = hook_color(line);
		if (map->floor == NULL)
			return (FAILURE);
	}
	if (ft_strncmp(line, "C ", 1) == 0)
	{
		map->ceiling = hook_color(line);
		if (map->ceiling == NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	hook_texture(t_map *map, const char *line, int id)
{
	if (map->texture[id] != NULL)
	{
		errno = EINVAL;
		return (FAILURE);
	}
	map->texture[id] = ft_strtrim(line + 3, " \t\n\r\v\f");
	if (map->texture[id] == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	take_texture(t_map *map, const char *line)
{
	if (ft_strncmp(line, "NO ", 2) == 0)
		return (hook_texture(map, line, NO));
	if (ft_strncmp(line, "SO ", 2) == 0)
		return (hook_texture(map, line, SO));
	if (ft_strncmp(line, "WE ", 2) == 0)
		return (hook_texture(map, line, WE));
	if (ft_strncmp(line, "EA ", 2) == 0)
		return (hook_texture(map, line, EA));
	return (SUCCESS);
}
