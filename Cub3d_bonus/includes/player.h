/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:55:57 by antgabri          #+#    #+#             */
/*   Updated: 2024/06/03 20:21:54 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "object.h"

# define PI 3.14159265359

typedef struct s_keys
{
	bool			up;
	bool			down;
	bool			right;
	bool			left;
	bool			rot_right;
	bool			rot_left;
	int				shift;
	bool			open_close;
	int				fire;
	int				reload;
	bool			esc;
	bool			grave;
}	t_keys;

typedef struct s_player
{
	t_keys			keys;
	float			speed;
	t_vector2		pos;
	t_vector2		dir;
	t_vector2		plane;
	t_vector2		delta;
	t_vector2		rot;
	float			rot_speed;
	void			(*move_up)(struct s_player *player);
	void			(*move_down)(struct s_player *player);
	void			(*move_right)(struct s_player *player);
	void			(*move_left)(struct s_player *player);
	void			(*rotate)(struct s_player *player, float rot_speed);
}	t_player;

void		init_move_player(t_player *player);

void		init_angle_player(t_player *player);

#endif