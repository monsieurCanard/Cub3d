/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:55:57 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/09 14:05:51 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "object.h"

# define PI 3.14159265359

typedef struct s_player
{
	t_object2d	*obj;
	t_vector2	delta;
	void		(*move_up)(struct s_player *player);
	void		(*move_down)(struct s_player *player);
	void		(*move_right)(struct s_player *player);
	void		(*move_left)(struct s_player *player);
	void		(*angle_right)(struct s_player *player);
	void		(*angle_left)(struct s_player *player);
}	t_player;

void	init_move_player(t_player *player);

void	init_angle_player(t_player *player);

#endif