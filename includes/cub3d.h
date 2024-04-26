/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:05:28 by anthony           #+#    #+#             */
/*   Updated: 2024/04/26 11:41:16 by antgabri         ###   ########.fr       */
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

# define WIDTH 1200
# define HEIGHT 1200

# define ERROR_MLX_INIT "Error while init_mlx"
# define ERROR_INIT_WINDOWS "Error while init windows"
# define ERROR_IMAGE "Error while init image"

# define ESCAPE 65307
# define SPACE 32
# define LEFT 65361
# define RIGHT 65363
# define UP 65364
# define DOWN 65362
# define PLUS 65451
# define MINUS 65453
# define ENTER 65293
# define QUIT 17


# define BLUE 0x0000FF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define BLACK 0x000000

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

typedef struct s_player
{
	double	x;
	double	y;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_player	player;
	t_map		map_data;
}				t_data;

//////////////////////////////////////////
/////////// INITIALISATION ///////////////
//////////////////////////////////////////

void		init_mlx(t_data *data);
void		init_image(t_data *data);

//////////////////////////////////////////
///////////// EVENTS /////////////////////
//////////////////////////////////////////

int			close_window(t_data *data);
int			key_press(int keycode, t_data *data);
int			key_release(int keycode, t_data *data);
// t_map		open_files(char *map_name);

//////////////////////////////////////////
///////////// PLAYER /////////////////////
//////////////////////////////////////////
void		create_player(t_data *data);

//////////////////////////////////////////
///////////// GAME ///////////////////////
//////////////////////////////////////////
void		my_pixel_put(t_img *img, int x, int y, int color);
void		create_game(t_data *data);
void		start_game(t_data *data);

#endif
