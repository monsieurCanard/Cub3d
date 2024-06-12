/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:04:21 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/12 10:49:16 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	verif_color(char **color)
{
	if (color == NULL
		|| (color[0] && ft_strlen(color[0]) > 3)
		|| (color[1] && ft_strlen(color[1]) > 3)
		|| (color[2] && ft_strlen(color[2]) > 3))
	{
		return (false);
	}
	return (true);
}

int	hook_color(t_argb *color, const char *line)
{
	char	**colors;

	if (color->is_set)
	{
		errno = EINVAL;
		return (FAILURE);
	}
	if (ft_strlen(line) < 5)
	{
		errno = EINVAL;
		return (FAILURE);
	}
	colors = split_color(line);
	if (verif_color(colors) == false)
	{
		return (FAILURE);
	}
	color->a = 255;
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);
	color->is_set = true;
	ft_rm_split(colors);
	return (SUCCESS);
}

int	take_colors(t_map *map, const char *line)
{
	if (ft_strncmp(line, "F ", 1) == 0)
	{
		if (hook_color(&map->floor, line) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(line, "C ", 1) == 0)
	{
		if (hook_color(&map->ceiling, line) == FAILURE)
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
	if (ft_strlen(line) < 3)
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
	if (ft_strncmp(line, "P ", 1) == 0)
		return (hook_texture(map, line, 4));
	if (ft_strncmp(line, "O ", 1) == 0)
		return (hook_texture(map, line, 5));
	return (SUCCESS);
}
