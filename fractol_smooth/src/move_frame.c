/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:29:32 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/04 21:15:37 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_move_frame(t_super *sup, double deltaX, double deltaY)
{
	double	ratio;

	ratio = sup->frm->zoom / INIT_ZOOM;
	sup->frm->px += deltaX * ratio;//sup->frm->zoom;
	sup->frm->py += deltaY * ratio;//sup->frm->zoom;
	if (sup->multiproc)
		frac_update_multiprocessor(sup);
	else
		frac_update(sup);
}

void	frac_set_frame_pos(t_super *sup, double x, double y)
{
	sup->frm->px = x;
	sup->frm->py = y;
	if (sup->multiproc)
		frac_update_multiprocessor(sup);
	else
		frac_update(sup);
}

void	frac_zoom(t_super *sup, double increment)
{
	sup->frm->zoom *= 1 + increment;
	if (sup->multiproc)
		frac_update_multiprocessor(sup);
	else
		frac_update(sup);
}

void	frac_rotate(t_super *sup, double delta_ang)
{
	printf("ATTEMPTING ROTATION !\n");
	sup->frm->ang += delta_ang;
	printf("NEW ANGLE AFTER ROTATION : %f\n", sup->frm->ang);
	if (sup->multiproc)
		frac_update_multiprocessor(sup);
	else
		frac_update(sup);
}