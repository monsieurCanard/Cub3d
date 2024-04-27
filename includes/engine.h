/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:24:40 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/26 22:53:13 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <stdio.h>
# include "core_data.h"
# include "libft.h"
# include <mlx.h>

# define WIDTH 1000
# define HEIGHT 1000

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

# define DEBUG 1

# define DEBUG_SQUARE_E "./debug/texture/empty_debug_square.xpm"
# define DEBUG_SQUARE_F "./debug/texture/full_debug_square.xpm"

# define DEBUG_SIZE 25


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
void		my_pixel_put(t_img *img, int x, int y, int color);
void		__create_void(t_engine *engine);

//////////////////////////////////////////
//////////////// EVENTS //////////////////
//////////////////////////////////////////


int			close_window(t_engine *engine);
int			key_press(int keycode, t_engine *engine);


//////////////////////////////////////////
/////////////// LOOP /////////////////////
//////////////////////////////////////////

void		e_loop(t_engine *engine);

//////////////////////////////////////////
/////////////// IMAGE ////////////////////
//////////////////////////////////////////

t_img	*init_xpm_img(void *p_engine, char *file, int width, int height);
void	put_img_to_window(void *p_engine, t_img *img, int x, int y);

#endif // ENGINE_H