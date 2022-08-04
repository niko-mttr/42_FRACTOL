/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:28:23 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 16:28:21 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mandelbrot(t_fract *f, double cr, double ci)
{
	double	temp;
	double	zr;
	double	zi;
	int		n;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < f->max)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		temp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * temp * zi + ci;
		n++;
	}
	return (n);
}

int	ft_julia(t_fract *f, double zr, double zi)
{
	int		n;
	double	temp;

	n = 0;
	while (n < f->max)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		temp = zr;
		zr = zr * zr - zi * zi + f->kr;
		zi = 2 * temp * zi + f->ki;
		n++;
	}
	return (n);
}
