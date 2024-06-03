/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:37:22 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 20:19:32 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int key_press2(int keycode, t_keys *keys)
{
	if (keycode == XK_grave)
	{
		if (keys->grave == 1)
			keys->grave = 0;
		else
			keys->grave = 1;
	}
}

int	key_press(int keycode, t_keys *keys)
{
	if (keycode == XK_Up || keycode == XK_w)
		keys->up = 1;
	if (keycode == XK_Down || keycode == XK_s)
		keys->down = 1;
	if (keycode == XK_Right)
		keys->rot_right = 1;
	if (keycode == XK_Left)
		keys->rot_left = 1;
	if (keycode == XK_a)
		keys->right = 1;
	if (keycode == XK_d)
		keys->left = 1;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		keys->shift = 1;
	if (keycode == XK_Escape)
		keys->esc = 1;
	if (keycode == XK_e)
		keys->open_close = 1;
	key_press2(keycode, keys);
	return (0);
}

int	key_release(int keycode, t_keys *keys)
{
	if (keycode == XK_Up || keycode == XK_w)
		keys->up = 0;
	if (keycode == XK_Down || keycode == XK_s)
		keys->down = 0;
	if (keycode == XK_Right)
		keys->rot_right = 0;
	if (keycode == XK_Left)
		keys->rot_left = 0;
	if (keycode == XK_a)
		keys->right = 0;
	if (keycode == XK_d)
		keys->left = 0;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		keys->shift = 0;
	if (keycode == XK_Escape)
		keys->esc = 0;
	return (0);
}
