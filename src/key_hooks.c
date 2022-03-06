/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:11:04 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/22 14:40:27 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "fractol.h"

static int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

static int	shift(int button, t_vars *vars)
{
	int	shift_x;
	int	shift_y;

	shift_x = 0;
	shift_y = 0;
	if (button == ARROW_UP)
		shift_y = -50;
	else if (button == ARROW_LEFT)
		shift_x = -50;
	else if (button == ARROW_DOWN)
		shift_y = 50;
	else if (button == ARROW_RIGHT)
		shift_x = 50;
	if (shift_x != 0 || shift_y != 0)
		draw_fractal(vars, 0, shift_x, shift_y);
	return (0);
}

static int	color_shift(t_vars *vars)
{
	static int	i = 0;

	if (i % 3 == 0)
		vars->params.color = put_color_pixel;
	else if (i % 3 == 1)
		vars->params.color = put_color_pixel2;
	else
		vars->params.color = put_color_pixel3;
	draw_fractal(vars, 0, 0, 0);
	++i;
	return (0);
}

static int	zoom(int button, t_vars *vars)
{
	if (button == BUTTON_PLUS)
		draw_fractal(vars, 2, W / 2, H / 2);
	else if (button == BUTTON_MINUS)
		draw_fractal(vars, 0.5, W / 2, H / 2);
	return (0);
}

int	key_hook(int button, t_vars *vars)
{
	if (button == ARROW_UP || button == ARROW_LEFT || \
		button == ARROW_DOWN || button == ARROW_RIGHT)
		shift(button, vars);
	else if (button == ESC)
		close(vars);
	else if (button == BUTTON_C)
		color_shift(vars);
	else if (button == BUTTON_PLUS || button == BUTTON_MINUS)
		zoom(button, vars);
	return (0);
}
