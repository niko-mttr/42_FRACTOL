/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:35:34 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 16:53:39 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_exit_msg(char *s, int errno)
{
	if (errno == 1)
		ft_putstr_fd("Error : ", 1);
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	return (errno);
}

int	end_fractol(t_fract *new)
{
	ft_clean_exit(0, new);
	return (0);
}

void	ft_clean_exit(int exit_code, t_fract *new)
{
	if (!new)
		exit(exit_code);
	if (new->win && new->mlx)
	{
		mlx_destroy_image(new->mlx, new->img);
		mlx_clear_window(new->mlx, new->win);
		mlx_destroy_window(new->mlx, new->win);
		mlx_destroy_display(new->mlx);
	}
	if (new->mlx)
		free(new->mlx);
	exit(exit_code);
}
