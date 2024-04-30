/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:24:40 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 17:12:45 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <stdio.h>
# include "core_data.h"
# include "libft.h"
# include <mlx.h>

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

# define VOID_COLOR 0x0000FF

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		color_offset;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_engine
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	e_void;
}	t_engine;

//////////////////////////////////////////
/////////// INITIALISATION ///////////////
//////////////////////////////////////////

void		*init_engine(void);
void		init_image(t_engine *engine);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		__create_void(t_engine *engine);

//////////////////////////////////////////
/////////// EVENTS ///////////////////////
//////////////////////////////////////////


int			close_window(t_engine *engine);
int			key_press(int keycode, t_engine *engine);

#endif // ENGINE_H