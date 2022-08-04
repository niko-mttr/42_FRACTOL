/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:24:17 by nmattera          #+#    #+#             */
/*   Updated: 2022/08/04 18:09:33 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef HEIGHT
#  define HEIGHT 900

# endif

# ifndef WIDTH
#  define WIDTH 900

# endif

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "key.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buff;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	max;
	int		color;
	int		form;
}			t_fract;

/* ****** fractol ****** */
void		ft_draw(t_fract *new);

/* ****** fractol_utils ****** */
int			ft_strcmp(char *s1, char *s2);
int			ft_pars_double(char *n);
int			ft_pars(int argc, char **option);

/* ****** fractol_event ****** */
int			key_event(int keycode, t_fract *mlx);
void		zoom(int keycode, t_fract *new);
int			ft_filter_zoom(int keycode, t_fract *new);
void		move(int keycode, double distance, t_fract *new);
int			mouse_event(int code, int x, int y, t_fract *new);

/* ****** fractol_init ****** */
void		ft_fill_struct(t_fract *new, char *name);
void		ft_init_img(t_fract *new);
void		ft_new_img(t_fract *new);
void		ft_init(t_fract *new);

/* ****** fractol_data ****** */
int			ft_check_arg(t_fract *new, int argc, char **argv);

/* ****** fracctol_color ****** */
int			ft_choose_color(int n, t_fract *f);

/* ****** fractol_mandelbrot ****** */
int			ft_mandelbrot(t_fract *f, double cr, double ci);
int			ft_julia(t_fract *f, double zr, double zi);

/* ****** fractol_exit ****** */
void		ft_clean_exit(int exit_code, t_fract *new);
int			end_fractol(t_fract *new);
int			ft_exit_msg(char *s, int errno);
void		ft_message(void);

#endif
