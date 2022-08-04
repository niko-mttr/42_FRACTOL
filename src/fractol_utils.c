/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:37:37 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 18:07:39 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_pars_double(char *n)
{
	int		i;

	i = 0;
	if (n[i] == '-')
		i++;
	while (n[i])
	{
		if (n[i] < '0' && n[i] > '9' && n[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int	ft_pars(int argc, char **option)
{
	if (argc < 2 || argc > 6 || !option[1][0])
	{
		ft_message();
		return (0);
	}
	if (!ft_strcmp("Mandelbrot", option[1]) || !ft_strcmp("Julia", option[1]))
		return (1);
	else
	{
		ft_message();
		return (0);
	}
}
