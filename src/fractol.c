/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:40:58 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 18:31:57 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fill_color(t_fract *new, int x, int y, int color)
{
	int	pixel;
	int	line_length;

	line_length = new->line_length;
	pixel = (line_length * y) + (x * 4);
	if (new->bits_per_pixel != 32)
		color = mlx_get_color_value(new->mlx, color);
	if (new->endian == 1)
	{
		new->buff[pixel] = (color >> 24);
		new->buff[pixel + 1] = (color >> 16) & 0xff;
		new->buff[pixel + 2] = (color >> 8) & 0xff;
		new->buff[pixel + 3] = (color) & 0xff;
	}
	else if (new->endian == 0)
	{
		new->buff[pixel] = (color) & 0xFF;
		new->buff[pixel + 1] = (color >> 8) & 0xFF;
		new->buff[pixel + 2] = (color >> 16) & 0xFF;
		new->buff[pixel + 3] = (color >> 24) & 0xFF;
	}
}

int	ft_fractal(t_fract *f, double cr, double ci)
{
	int	n;

	if (f->form == MANDELBROT)
		n = ft_mandelbrot(f, cr, ci);
	if (f->form == JULIA)
		n = ft_julia(f, cr, ci);
	return (n);
}

void	ft_draw(t_fract *new)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		n;

	mlx_clear_window(new->mlx, new->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = new->min_r + (double)x *(new->max_r - new->min_r) / WIDTH;
			pi = new->min_i + (double)y *(new->max_i - new->min_i) / HEIGHT;
			n = ft_fractal(new, pr, pi);
			ft_fill_color(new, x, y, ft_choose_color(n, new));
		}
	}
	mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fract	new;

	if (!ft_pars(argc, argv))
		return (EXIT_FAILURE);
	ft_fill_struct(&new, argv[1]);
	if (!ft_check_arg(&new, argc, argv))
	{
		ft_message();
		return (EXIT_FAILURE);
	}
	ft_init(&new);
	ft_draw(&new);
	mlx_hook(new.win, 17, 1L << 2, end_fractol, &new);
	mlx_mouse_hook(new.win, mouse_event, &new);
	mlx_key_hook(new.win, key_event, &new);
	mlx_loop(new.mlx);
}
