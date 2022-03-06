/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:10:09 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/22 14:30:38 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "errors.h"

static int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		++i;
	}
	if (i != n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	else
		return (0);
}

void	init_params(t_vars *vars, char *nbr1, char *nbr2)
{
	set_complex(&vars->params.c, ft_atof(nbr1), ft_atof(nbr2));
}

void	choose_fract(t_vars *vars, char *name)
{
	if (!ft_strncmp(name, "mandelbrot", 10))
	{
		vars->fract = mandelbrot;
		set_complex(&vars->params.max, 1, 1.2);
		set_complex(&vars->params.min, -2, -1.2);
	}
	else if (!ft_strncmp(name, "julia", 5))
	{
		vars->fract = julia;
		set_complex(&vars->params.max, 2, 2);
		set_complex(&vars->params.min, -2, -2);
	}
	else if (!ft_strncmp(name, "burning ship", 12))
	{
		vars->fract = burning_ship;
		set_complex(&vars->params.max, 1.5, 1);
		set_complex(&vars->params.min, -2.5, -2);
	}
	else
		error(ERROR_INIT);
	vars->params.color = put_color_pixel3;
}
