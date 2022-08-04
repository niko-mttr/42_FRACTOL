/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 10:07:41 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 18:24:40 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_check_color(char *color, t_fract *new)
{
	if (!ft_strcmp(color, "blue"))
	{
		new->color = BLUE;
		return (1);
	}
	if (!ft_strcmp(color, "red"))
	{
		new->color = RED;
		return (1);
	}
	if (!ft_strcmp(color, "purple"))
	{
		new->color = PURPLE;
		return (1);
	}
	if (!ft_strcmp(color, "rainbow"))
	{
		new->color = RAINBOW;
		return (1);
	}
	return (0);
}

int	ft_minus(char *arr)
{
	if (arr[0] == '-')
		return (-1);
	return (1);
}

double	ft_atof(char *arr, double val, int afterdot, double scale)
{
	char	*cpy;

	cpy = arr;
	if (ft_minus(arr) == -1)
		arr++;
	while (*arr)
	{
		if (afterdot)
		{
			scale = scale / 10;
			val = val + (*arr - '0') * scale;
		}
		else
		{
			if (*arr == '.')
				afterdot++;
			else
				val = val * 10.0 + (*arr - '0');
		}
		arr++;
	}
	return (val * ft_minus(cpy));
}

int	ft_check_depth(char *n, t_fract *new)
{
	int	i;

	i = 0;
	if (ft_strlen(n) < 2 || ft_strlen(n) > 3)
		return (0);
	while (n[i])
	{
		if (n[i] > '0' && n[i] > '9')
			return (0);
		i++;
	}
	new->max = ft_atoi(n);
	return (1);
}

int	ft_check_arg(t_fract *new, int argc, char **argv)
{
	int	r;

	r = 1;
	if (!ft_strcmp(argv[1], "Julia") && argc >= 4)
	{
		if (!ft_pars_double(argv[2]) || !ft_pars_double(argv[3]))
			return (0);
		new->kr = ft_atof(argv[2], 0, 0, 1);
		new->ki = ft_atof(argv[3], 0, 0, 1);
	}
	if (!ft_strcmp(argv[1], "Mandelbrot") && argc >= 3)
		r = (ft_check_color(argv[2], new));
	if (!ft_strcmp(argv[1], "Julia") && argc >= 5)
		r = (ft_check_color(argv[4], new));
	if (!ft_strcmp(argv[1], "Mandelbrot") && argc == 4)
		r = (ft_check_depth(argv[3], new));
	if (!ft_strcmp(argv[1], "Julia") && argc == 6)
		r = (ft_check_depth(argv[5], new));
	return (r);
}
