/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:39:07 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 16:28:16 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_side(int keycode, double distance, t_fract *new)
{
	double	center_i;
	double	center_r;

	center_r = new->max_r - new->min_r;
	center_i = new->max_i - new->min_i;
	if (keycode == KEY_RIGHT)
	{
		new->min_r += center_r * distance;
		new->max_r += center_r * distance;
	}
	if (keycode == KEY_LEFT)
	{
		new->min_r -= center_r * distance;
		new->max_r -= center_r * distance;
	}
	ft_draw(new);
}

void	move_high(int keycode, double distance, t_fract *new)
{
	double	center_i;
	double	center_r;

	center_r = new->max_r - new->min_r;
	center_i = new->max_i - new->min_i;
	if (keycode == KEY_DOWN)
	{
		new->max_i += center_i * distance;
		new->min_i += center_i * distance;
	}
	if (keycode == KEY_UP)
	{
		new->max_i -= center_i * distance;
		new->min_i -= center_i * distance;
	}
	ft_draw(new);
}

void	zoom(int keycode, t_fract *f)
{
	double	coef;
	double	center_r;
	double	center_i;

	coef = 2.0;
	center_r = f->min_r - f->max_r;
	center_i = f->min_i - f->max_i;
	if (keycode == KEY_PLUS || keycode == 4)
		coef = 0.5;
	f->min_r = f->max_r + coef * center_r;
	f->max_r = f->max_r + (center_r - coef * center_r) / 2;
	f->min_i = f->max_i + coef * (center_i);
	f->max_i = f->max_i + (center_i - coef * center_i) / 2;
	ft_draw(f);
}

int	key_event(int keycode, t_fract *new)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(new);
		return (0);
	}
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		zoom(keycode, new);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move_side(keycode, 0.3, new);
	if (keycode == KEY_DOWN || keycode == KEY_UP)
		move_high(keycode, 0.3, new);
	return (1);
}

int	mouse_event(int code, int x, int y, t_fract *new)
{
	if (code == 4)
	{
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		zoom(code, new);
		if (x < 0)
			move_side(KEY_LEFT, (double)(x * -5) / WIDTH, new);
		else
			move_side(KEY_RIGHT, (double)x / WIDTH, new);
		if (y < 0)
			move_high(KEY_UP, (double)(y * -6) / HEIGHT, new);
		else
			move_high(KEY_DOWN, (double)y / HEIGHT, new);
	}
	if (code == 5)
		zoom(code, new);
	return (1);
}
