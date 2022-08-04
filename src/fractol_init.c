/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:49:23 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 16:28:13 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_adapt(t_fract *new)
{
	new->form = JULIA;
	new->min_r = -2.0;
	new->max_r = 2.0;
	new->min_i = -2.0;
	new->max_i = new->min_i + (new->max_r - new->min_r) * HEIGHT / WIDTH;
}

void	ft_fill_struct(t_fract *new, char *name)
{
	new->mlx = NULL;
	new->win = NULL;
	new->img = NULL;
	new->buff = NULL;
	new->min_r = -2.0;
	new->max_r = 1.0;
	new->min_i = -1.5;
	new->max_i = new->min_i + (new->max_r - new->min_r) * HEIGHT / WIDTH;
	new->kr = 0;
	new->ki = 0;
	new->form = 0;
	new->color = BLUE;
	new->max = 80;
	new->form = MANDELBROT;
	if (!ft_strcmp(name, "Julia"))
		ft_adapt(new);
}

void	ft_init_img(t_fract *new)
{
	char	*buff;

	new->img = mlx_new_image(new->mlx, WIDTH, HEIGHT);
	if (!new->img)
		ft_clean_exit(ft_exit_msg("MLX", 1), new);
	buff = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length,
			&new->endian);
	new->buff = buff;
}

void	ft_new_img(t_fract *new)
{
	if (new->mlx && new->img)
		mlx_destroy_image(new->mlx, new->img);
	if (new->buff)
		new->buff = NULL;
	ft_init_img(new);
}

void	ft_init(t_fract *new)
{
	new->mlx = mlx_init();
	if (!new->mlx)
		ft_clean_exit(ft_exit_msg("MLX", 1), new);
	new->win = mlx_new_window(new->mlx, WIDTH, HEIGHT, "Fractol_Window");
	if (!new->win)
		ft_clean_exit(ft_exit_msg("MLX", 1), new);
	ft_new_img(new);
}
