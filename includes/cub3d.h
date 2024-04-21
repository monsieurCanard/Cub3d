/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthony <anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:05:28 by anthony           #+#    #+#             */
/*   Updated: 2024/04/20 18:01:17 by anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"

# define FAILURE -1
# define SUCCESS 0
//MAIN
typedef struct s_map
{
	int			fd_map;
	int			fd_texture[5];
	char		**map;
	
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map_data;
}				t_data;


t_map		open_files(char *map_name);

#endif
