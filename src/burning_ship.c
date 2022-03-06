/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:09:27 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/22 14:26:30 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	find_set_points(t_complex c, t_complex *z)
{
	int			i;
	t_complex	temp;
	t_complex	old_z;

	i = 0;
	set_complex(&temp, z->x, z->y);
	set_complex(&old_z, z->x, z->y);
	while (i < MAX_ITERATIONS && (temp.x + temp.y <= 4))
	{
		set_complex(z, temp.x - temp.y + c.x, fabs(2 * z->x * z->y) + c.y);
		set_complex(&temp, z->x * z->x, z->y * z->y);
		++i;
		if (z->x == old_z.x && z->y == old_z.y)
			i = MAX_ITERATIONS;
		if (i % 20 == 0)
			set_complex(&old_z, z->x, z->y);
	}
	return (i);
}

void	burning_ship(t_data *data, t_fract fract)
{
	t_complex	c;
	t_complex	z;
	t_point		p;
	int			i;

	p.y = 0;
	while (p.y < H)
	{
		p.x = 0;
		c.y = p.y * (fract.max.y - fract.min.y) / H + fract.min.y;
		while (p.x < W)
		{
			set_complex(&z, 0, 0);
			c.x = p.x * (fract.max.x - fract.min.x) / W + fract.min.x;
			i = find_set_points(c, &z);
			if (i != MAX_ITERATIONS)
				fract.color(data, z, i, p);
			++p.x;
		}
		++p.y;
	}
}
