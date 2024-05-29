/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:26:59 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 11:54:32 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	check_digit(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static char	**format_split(char **colors)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (colors[i] != NULL)
	{
		tmp = ft_strtrim(colors[i], " \t\n\r\v\f");
		if (tmp && check_digit(tmp) == false)
		{
			ft_rm_split(colors);
			return (errno = EINVAL, NULL);
		}
		if (tmp == NULL || ft_atoi(tmp) > 255 || ft_atoi(tmp) < 0)
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

char	**split_color(const char *line)
{
	char	**colors;

	colors = ft_split(line + 2, ',');
	if (colors == NULL)
		return (NULL);
	if (ft_tablen((const char **)colors) != 3)
	{
		ft_rm_split(colors);
		return (errno = EINVAL, NULL);
	}
	colors = format_split(colors);
	return (colors);
}
