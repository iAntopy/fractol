/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_switchs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:37:57 by iamongeo          #+#    #+#             */
/*   Updated: 2022/09/08 09:09:19 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	mouse_in_window(int x, int y)
{
	return ((y >= 0) && (x >= 0) && (y < SCN_HEIGHT) && (x < SCN_WIDTH));
}

int	init_mouse_data(t_super *sup)
{
	sup->mouse_1_pressed = 0;
	sup->mouse_3_pressed = 0;
	sup->mouse_1_dragging = 0;
	sup->mouse_3_dragging = 0;
	return (0);
}

int	on_mouse_press(int button, int x, int y, t_super *sup)
{
	if (!mouse_in_window(x, y))
		return (0);
	else if (button == 1)
	{
		sup->mouse_1_pressed = 1;
		sup->last_x = x;
		sup->last_y = y;
	}
	else if (button == 3)
	{
		sup->mouse_3_pressed = 1;
		sup->last_x = x;
		sup->last_y = y;
	}
	else if (button == 4)
		frac_dir_zoom(sup, x, y, ZOOM_INCREMENT);
	else if (button == 5)
		frac_dir_zoom(sup, x, y, -ZOOM_INCREMENT);
	return (0);
}

// Moves frame to mouse position (left click) or get dist data at pix (right).
int	on_mouse_release(int button, int x, int y, t_super *sup)
{
	t_pix	pix;
	t_frm	*frm;

	if (!mouse_in_window(x, y))
		return (init_mouse_data(sup));
	frm = &sup->frm;
	pix.sx = x;
	pix.sy = y;
	convert_pix_to_frame(frm, &pix);
	if (button == 1 && !sup->mouse_1_dragging)
		frac_set_frame_pos(sup, pix.fx, pix.fy);
	return (init_mouse_data(sup));
}

int	on_mouse_drag(int x, int y, t_super *sup)
{
	if (!mouse_in_window(x, y))
		return (0);
	else if (sup->mouse_1_pressed)
	{
		sup->mouse_1_dragging = 1;
		frac_move_frame(sup, sup->last_x - x, sup->last_y - y);
	}
	else if (sup->mouse_3_pressed)
	{
		sup->mouse_3_dragging = 1;
		frac_set_julia_shift(sup, x, y);
	}
	sup->last_x = x;
	sup->last_y = y;
	return (0);
}
