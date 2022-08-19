/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:29:32 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/18 23:24:01 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_move_frame(t_super *sup, double deltaX, double deltaY)
{
	t_pix	pix;

	pix.sx = deltaX;
	pix.sy = deltaY;
	convert_vect_to_frame(sup->frm, &pix);
	sup->frm->px += pix.fx;
	sup->frm->py += pix.fy;
	frac_update(sup);
}

void	frac_set_frame_pos(t_super *sup, double x, double y)
{
	sup->frm->px = x;
	sup->frm->py = y;
	frac_update(sup);
}

void	frac_rotate(t_super *sup, double delta_ang)
{
	sup->frm->ang += delta_ang;
	frac_update(sup);
}

void	frac_reset_frame(t_super *sup)
{
	sup->frm->px = INIT_POSX;
	sup->frm->py = INIT_POSY;
	sup->frm->zoom = INIT_ZOOM;
	sup->frm->ang = INIT_ANGLE;
	frac_update(sup);
}
