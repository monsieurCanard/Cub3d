/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:04:21 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/25 18:41:34 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**split_color(const char *line)
{
	int		i;
	char	**colors;
	char	*tmp;

	colors = ft_split(line + 2, ',');
	if (colors == NULL)
		return (NULL);
	if (ft_tablen((const char **)colors) != 3)
	{
		errno = EINVAL;
		ft_rm_split(colors);
		return (NULL);
	}
	i = 0;
	while (colors[i] != NULL)
	{
		// TODO: check if is digit
		tmp = ft_strtrim(colors[i], " \t\n\r\v\f");
		if (tmp == NULL)
		{
			ft_rm_split(colors);
			return (NULL);
		}
		free(colors[i]);
		colors[i] = tmp;
		i++;
	}
	return (colors);
}

static bool	verif_color_range(t_argb *color)
{
	if (color->r < 0 || color->r > 255)
		return (false);
	if (color->g < 0 || color->g > 255)
		return (false);
	if (color->b < 0 || color->b > 255)
		return (false);
	return (true);
}

t_argb	*take_colors(const char *line)
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
	if (verif_color_range(color) == false)
	{
		errno = EINVAL;
		free(color);
		ft_rm_split(colors);
		return (NULL);
	}
	ft_rm_split(colors);
	return (color);
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
