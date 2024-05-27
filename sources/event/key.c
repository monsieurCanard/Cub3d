/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:37:22 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 17:41:36 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_keys *keys)
{
	if (keycode == XK_Up || keycode == XK_w)
		keys->up = 1;
	if (keycode == XK_Down || keycode == XK_s)
		keys->down = 1;
	if (keycode == XK_Right)
		keys->right = 1;
	if (keycode == XK_Left)
		keys->left = 1;
	if (keycode == XK_a)
		keys->rotate_left = 1;
	if (keycode == XK_d)
		keys->rotate_right = 1;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		keys->shift = 1;
	return (0);
}

int	key_release(int keycode, t_keys *keys)
{
	if (keycode == XK_Up || keycode == XK_w)
		keys->up = 0;
	if (keycode == XK_Down || keycode == XK_s)
		keys->down = 0;
	if (keycode == XK_Right)
		keys->right = 0;
	if (keycode == XK_Left)
		keys->left = 0;
	if (keycode == XK_a)
		keys->rotate_left = 0;
	if (keycode == XK_d)
		keys->rotate_right = 0;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		keys->shift = 0;
	return (0);
}
