/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:14:36 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/22 14:40:10 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# define MAX_ITERATIONS 300
# define W 800
# define H 600

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fract
{
	t_complex	max;
	t_complex	min;
	t_complex	c;
	void		(*color)(t_data *, t_complex, int, t_point);
}	t_fract;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		(*fract)(t_data *, t_fract);
	t_fract		params;
}	t_vars;

void	put_color_pixel(t_data *data, t_complex z, int i, t_point p);
void	put_color_pixel2(t_data *data, t_complex z, int i, t_point p);
void	put_color_pixel3(t_data *data, t_complex z, int i, t_point p);

void	julia(t_data *img, t_fract fract);
void	mandelbrot(t_data *data, t_fract fract);
void	burning_ship(t_data *data, t_fract fract);

void	set_complex(t_complex *z, double x, double y);
double	get_factor(t_complex c);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	choose_fract(t_vars *vars, char *name);
void	init_params(t_vars *vars, char *nbr1, char *nbr2);
double	ft_atof(char *str);

int		close_crest(void *param);
int		key_hook(int button, t_vars *vars);

void	apply_zoom(t_vars *fract, t_complex mouse, double zoom);
void	apply_shift(t_vars *fract, double x, double y);
int		mouse_hook(int button, int x, int y, t_vars *vars);

void	help(void);
void	draw_fractal(t_vars *vars, double zoom, int x_center, int y_center);
void	error(char *msg);

#endif
