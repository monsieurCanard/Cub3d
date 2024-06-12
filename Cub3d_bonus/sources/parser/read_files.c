/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:29:31 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/07 10:59:41 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	take_data(t_map *map, const char *raw_line)
{
	char	*line;
	int		ret;

	line = ft_strtrim(raw_line, " \t\n\r\v\f");
	if (line == NULL)
		return (FAILURE);
	if (line[0] == '\0')
	{
		free(line);
		return (SUCCESS);
	}
	if (is_coord_id(line) == true)
	{
		ret = take_texture(map, line);
		free(line);
		return (ret);
	}
	if (ft_strncmp(line, "F ", 1) == 0 || ft_strncmp(line, "C ", 1) == 0)
	{
		ret = take_colors(map, line);
		free(line);
		return (ret);
	}
	free(line);
	return (SUCCESS);
}

static int	save_data(t_map *map, t_list **lst_map, const char *raw_line)
{
	if (is_map(map, raw_line) == false)
	{
		if (take_data(map, raw_line) == FAILURE)
		{
			return (FAILURE);
		}
	}
	else
	{
		if (save_map_lst(lst_map, raw_line) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static char	*get_raw_line(int fd_map, t_list *lst_map)
{
	char	*raw_line;
	char	*line;

	(void)lst_map;
	raw_line = get_next_line(fd_map);
	if (raw_line == NULL)
		return (NULL);
	if (raw_line[0] == '\n' && ft_lstsize(lst_map) != 0)
	{
		free(raw_line);
		line = ft_strdup("coucou\n");
		if (line == NULL)
			return (NULL);
		return (line);
	}
	line = ft_strtrim(raw_line, "\n");
	free(raw_line);
	if (line == NULL)
		return (NULL);
	return (line);
}

static int	read_file_error(char *raw_line, int fd_map)
{
	char	*line;

	while (true)
	{
		line = get_raw_line(fd_map, NULL);
		if (line == NULL)
			break ;
		free(line);
	}
	errno = print_error("Data from file .cub invalid", ENOMEM);
	if (raw_line != NULL)
	{
		free(raw_line);
	}
	return (FAILURE);
}

int	read_files(t_map *map, int fd_map)
{
	char	*raw_line;
	t_list	*lst_map;
	int		ret;

	lst_map = NULL;
	while (true)
	{
		raw_line = get_raw_line(fd_map, lst_map);
		if (raw_line == NULL)
			break ;
		ret = is_empty_line(raw_line);
		if (ret == FAILURE)
			return (read_file_error(raw_line, fd_map));
		else if (ft_lstsize(lst_map) == 0 && ret == true)
		{
			free(raw_line);
			continue ;
		}
		if (save_data(map, &lst_map, raw_line) == FAILURE)
			return (read_file_error(raw_line, fd_map));
		free(raw_line);
	}
	if (take_map(map, &lst_map) == FAILURE)
		return (read_file_error(NULL, fd_map));
	return (close(fd_map), SUCCESS);
}
