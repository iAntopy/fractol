/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 04:13:36 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/27 05:35:40 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_zoom(t_super *sup, double increment)
{
	sup->frm.zoom *= 1 + increment;
	frac_update(sup);
}

void	frac_dir_zoom(t_super *sup, double x, double y, double increment)
{
	t_frm	*frm;
	t_pix	pix;

	frm = &sup->frm;
	pix.sx = x - frm->scn_midx;
	pix.sy = y - frm->scn_midy;
	convert_vect_to_frame(frm, &pix);
	frm->px += pix.fx * increment * 1.1;
	frm->py += pix.fy * increment * 1.1;
	frm->zoom *= (1 - increment);
	frac_update(sup);
}
