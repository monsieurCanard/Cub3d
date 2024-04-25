/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:05:28 by anthony           #+#    #+#             */
/*   Updated: 2024/04/25 16:19:35 by Monsieur_Ca      ###   ########.fr       */
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
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define FAILURE -1
# define SUCCESS 0

# define WIDTH 800
# define HEIGHT 800

# define ERROR_MLX_INIT "Error while init_mlx"
# define ERROR_INIT_WINDOWS "Error while init windows"

//MAIN
typedef struct s_map
{
	int			fd_map;
	int			fd_texture[5];
	char		**map;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		color_offset;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map_data;
}				t_data;


t_map		open_files(char *map_name);

#endif
