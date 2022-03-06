/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:09:38 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/21 18:10:48 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	pcolor(int r, int g, int b)
{
	return (b + g * 256 + r * 256 * 256);
}

static int	guasiperiod_color(double z, int i)
{
	double	r;
	double	g;
	double	b;
	double	k;

	k = 1;
	z = log(z) / pow(2, i);
	z = log(z) / k;
	r = 255 * (1 - cos(z / log(2))) / 2;
	g = 255 * (1 - cos(z / (log(2) * 3 * sqrt(2)))) / 2;
	b = 255 * (1 - cos(z / (log(2) * 7 * pow(3, 1 / 8)))) / 2;
	return (pcolor(r, g, b));
}

void	put_color_pixel(t_data *data, t_complex z, int i, t_point p)
{
	double	abc_z;
	int		bright;

	abc_z = sqrt(z.x * z.x + z.y * z.y);
	bright = 256. * log2(1.75 + i - log2(log2(abc_z))) / log2(MAX_ITERATIONS);
	my_mlx_pixel_put(data, p.x, p.y, pcolor(bright, bright, 255));
}

void	put_color_pixel2(t_data *data, t_complex z, int i, t_point p)
{
	double	abc_z;

	abc_z = sqrt(z.x * z.x + z.y * z.y);
	my_mlx_pixel_put(data, p.x, p.y, guasiperiod_color(abc_z, i));
}

void	put_color_pixel3(t_data *data, t_complex z, int i, t_point p)
{
	double	abc_z;
	int		bright;

	abc_z = sqrt(z.x * z.x + z.y * z.y);
	bright = 256. * log2(1.75 + i - log2(log2(abc_z))) / log2(MAX_ITERATIONS);
	my_mlx_pixel_put(data, p.x, p.y, pcolor(255, bright, bright));
}
