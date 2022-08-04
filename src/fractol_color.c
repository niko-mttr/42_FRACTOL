/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:52:38 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 16:28:19 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	rainbow(int n, t_fract *f)
{
	if (n == f->max)
		return (0x000000);
	else if (n > f->max / (f->max * 0.045))
		return (0x5B0384);
	else if (n > f->max / (f->max * 0.064))
		return (0xD30404);
	else if (n > f->max / (f->max * 0.094))
		return (0xFD8900);
	else if (n > f->max / (f->max * 0.11))
		return (0xF8FD00);
	else if (n > f->max / (f->max * 0.135))
		return (0x00FD19);
	else if (n > f->max / (f->max * 0.15))
		return (0x3FFFDC);
	else if (n > f->max / (f->max * 0.2))
		return (0x4326F5);
	else if (n > f->max / (f->max * 0.24))
		return (0x4F26F5);
	else if (n > f->max / (f->max * 0.28))
		return (0x7526F5);
	else if (n > f->max / (f->max * 0.34))
		return (0x8126F5);
	else if (n > f->max / (f->max * 0.52))
		return (0x8E26F5);
	return (0x9A26F5);
}

int	purple(int n, t_fract *f)
{
	if (n == f->max)
		return (0x244046);
	else if (n > f->max / (f->max * 0.045))
		return (0x23F1FE);
	else if (n > f->max / (f->max * 0.064))
		return (0xFE23CE);
	else if (n > f->max / (f->max * 0.12))
		return (0xD223FE);
	else if (n > f->max / (f->max * 0.2))
		return (0xA308CA);
	else if (n > f->max / (f->max * 0.218))
		return (0x7E019D);
	else if (n > f->max / (f->max * 0.26))
		return (0x5B0172);
	return (0x330140);
}

int	red(int n, t_fract *f)
{
	if (n == f->max)
		return (0x000000);
	else if (n > f->max / (f->max * 0.045))
		return (0x92FC0A);
	else if (n > f->max / (f->max * 0.064))
		return (0xFAFE23);
	else if (n > f->max / (f->max * 0.12))
		return (0xFE5723);
	else if (n > f->max / (f->max * 0.2))
		return (0xDD1B1B);
	else if (n > f->max / (f->max * 0.218))
		return (0xB71414);
	else if (n > f->max / (f->max * 0.26))
		return (0x830F0F);
	return (0x3C0101);
}

int	blue(int n, t_fract *f)
{
	if (n == f->max)
		return (0x000000);
	else if (n > f->max / (f->max * 0.028))
		return (0x23F1FE);
	else if (n > f->max / (f->max * 0.036))
		return (0xA5F1F5);
	else if (n > f->max / (f->max * 0.1))
		return (0x013B3F);
	else if (n > f->max / (f->max * 0.2))
		return (0x002426);
	else if (n > f->max / (f->max * 0.218))
		return (0x002224);
	else if (n > f->max / (f->max * 0.26))
		return (0x001A1C);
	return (0x00000);
}

int	ft_choose_color(int n, t_fract *f)
{
	int	color;

	if (!f->color)
		color = blue(n, f);
	else if (f->color == RED)
		color = red(n, f);
	else if (f->color == PURPLE)
		color = purple(n, f);
	else if (f->color == RAINBOW)
		color = rainbow(n, f);
}
