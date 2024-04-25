/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:30:07 by anthony           #+#    #+#             */
/*   Updated: 2024/04/25 16:41:30 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// static int	open_map(char *map_name)
// {
// 	int	fd;

// 	if (access(map_name, F_OK) == -1)
// 	{
// 		errno = ENOENT;
// 		return (perror("Error"), FAILURE);
// 	}
// 	fd = open(map_name, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		errno = ENOENT;
// 		return (perror("Error"), FAILURE);
// 	}
// 	return (fd);
// }

// static char	**get_map(int fd)
// {
// 	char	*line;
// 	char	**map;
// 	int		i;

// 	i = 0;
// 	while (get_next_line(fd, &line) > 0) //Je me place au niveau du C majuscule car c'est toujours la derniere ligne avant la map
// 	{
// 		if (ft_strchr(line, 'C') != NULL)
// 			break;
// 		free(line);
// 	}
// 	while (get_next_line(fd, &line) > 0)// Je descend jusaqu'a trouver un 1 ou un 0 pour commencer la map
// 	{
// 		if (ft_strchr(line, '1') != NULL)
// 			break;
// 		ft_strchr(line, '0') != NULL)// Si y'a un zero c'est que la map n'est pas bien formater
// 			return (free(line), NULL);
// 		free(line);
// 	}
// 	map = malloc(sizeof(char *) * ft_strlen(line) + 1); //Je malloc la taille de la ligne
// 	if (map == NULL)
// 		return (free(line), NULL);
// 	while (get_next_line(fd, &line) > 0 && (ft_strchr(line, '1') == NULL && ft_strchr(line, '0') == NULL))
// 	{
// 		map[i] = ft_strdup(line);
// 		if (map[i] == NULL)
// 			return (free(line), ft_rmsplit(map), NULL);
// 		i++;
// 	}
// 	map[i] = NULL;
// 	return (map);
// }

// t_map	open_files(char *map_name)
// {
// 	t_map	map_data;

// 	map_data.fd_map = open_map(map_name);
// 	if (map_data.fd_map == FAILURE)
// 		exit(errno);
// 	map_data.map = get_map(map_data.fd_map);
// 	if (map_data.map == NULL)
// 	{
// 		errno = EINVAL;
// 		exit(errno);
// 	}
// 	// map_data.fd_texture = open_texture(map_data.fd_map);
// 	return (map_data);
// }