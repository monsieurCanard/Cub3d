/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:55:57 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/16 12:58:27 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "object.h"
# include "input.h"

# define PI 3.14159265359

typedef struct s_player
{
	t_game_object	*obj;
	t_vector2		delta;
	t_keys			keys;
	float			speed;
	void			(*move_up)(struct s_player *player);
	void			(*move_down)(struct s_player *player);
	void			(*move_right)(struct s_player *player);
	void			(*move_left)(struct s_player *player);
	void			(*angle_right)(struct s_player *player);
	void			(*angle_left)(struct s_player *player);
}	t_player;

void	init_move_player(t_player *player);

void	init_angle_player(t_player *player);

void	cal_delta(t_player *player);

#endif