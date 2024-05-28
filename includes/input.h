/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgabri <antgabri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:42:21 by antgabri          #+#    #+#             */
/*   Updated: 2024/05/28 09:43:15 by antgabri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef struct s_keys
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		shift;
}			t_keys;

int			key_release(int keycode, t_keys *keys);

int			key_press(int keycode, t_keys *keys);

#endif