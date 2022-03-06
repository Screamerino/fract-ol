/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:11:29 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/22 14:27:20 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	apply_zoom(t_vars *fract, t_complex mouse, double zoom)
{
	double	coef;

	coef = 1.0 / zoom;
	fract->params.min.x = interpolate(mouse.x, fract->params.min.x, coef);
	fract->params.min.y = interpolate(mouse.y, fract->params.min.y, coef);
	fract->params.max.x = interpolate(mouse.x, fract->params.max.x, coef);
	fract->params.max.y = interpolate(mouse.y, fract->params.max.y, coef);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == MOUSE_SCROLL_IN)
		draw_fractal(vars, 2, x, y);
	else if (button == MOUSE_SCROLL_OUT)
		draw_fractal(vars, 0.5, x, y);
	return (0);
}
