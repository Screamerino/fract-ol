/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:09:47 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/21 18:10:49 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_factor(t_complex c)
{
	double	a;

	a = pow(c.x, 2) + pow(c.y, 2);
	return ((1 + 2 * a + sqrt(1 + 4 * a)) / 2 + 1);
}

void	set_complex(t_complex *z, double x, double y)
{
	z->x = x;
	z->y = y;
}
