/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:10:57 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/22 14:25:51 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	find_set_points(t_complex *z, t_complex c)
{
	t_complex	old_z;
	t_complex	temp;
	int			i;
	double		factor;

	i = 0;
	factor = get_factor(c);
	set_complex(&old_z, z->x, z->y);
	set_complex(&temp, z->x * z->x, z->y * z->y);
	while (i < MAX_ITERATIONS && (temp.x + temp.y <= factor))
	{
		set_complex(z, temp.x - temp.y + c.x, 2 * z->x * z->y + c.y);
		set_complex(&temp, z->x * z->x, z->y * z->y);
		++i;
		if (z->x == old_z.x && z->y == old_z.y)
			i = MAX_ITERATIONS;
		if (i % 20 == 0)
			set_complex(&old_z, z->x, z->y);
	}
	return (i);
}

void	julia(t_data *data, t_fract fract)
{
	t_point		p;
	int			i;
	t_complex	z;
	t_complex	c;

	p.x = 0;
	set_complex(&c, fract.c.x, fract.c.y);
	while (p.x < W)
	{
		p.y = 0;
		while (p.y < H)
		{
			z.y = p.y * (fract.max.y - fract.min.y) / H + fract.min.y;
			z.x = p.x * (fract.max.x - fract.min.x) / W + fract.min.x;
			i = find_set_points(&z, c);
			if (i != MAX_ITERATIONS)
				fract.color(data, z, i, p);
			++p.y;
		}
		++p.x;
	}
}
