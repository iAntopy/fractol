/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:33:45 by iamongeo          #+#    #+#             */
/*   Updated: 2022/08/10 23:06:46 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	frac_shift_julia(t_super *sup, double real, double imag)
{
	sup->frm.cx += real;
	sup->frm.cy += imag;
	printf("New c coord after julia shift : (%f %f)\n", sup->frm.cx, sup->frm.cy);
	sup->needs_update = 1;
}

void	frac_set_julia_shift(t_super *sup, double real, double imag)
{
	sup->frm.cx = real;
	sup->frm.cy = imag;
	printf("New c value : (%f %f)\n", sup->frm.cx, sup->frm.cy);
	sup->needs_update = 1;
}