/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:11:11 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/22 14:36:31 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "errors.h"

void	apply_shift(t_vars *fract, double x, double y)
{
	fract->params.max.x = x + fract->params.max.x - fract->params.min.x;
	fract->params.min.x = x;
	fract->params.max.y = y + fract->params.max.y - fract->params.min.y;
	fract->params.min.y = y;
}

void	draw_fractal(t_vars *vars, double zoom, int x, int y)
{
	t_data		img;
	t_complex	mouse;
	t_fract		fract;

	fract = vars->params;
	mouse.x = (double) x / (W / (fract.max.x - fract.min.x)) + fract.min.x;
	mouse.y = (double) y / (H / (fract.max.y - fract.min.y)) + fract.min.y;
	if (zoom != 0)
		apply_zoom(vars, mouse, zoom);
	else
		apply_shift(vars, mouse.x, mouse.y);
	img.img = mlx_new_image(vars->mlx, W, H);
	if (!img.img)
		error(ERROR_IMG);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	vars->fract(&img, vars->params);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	mlx_destroy_image(vars->mlx, img.img);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 1)
		help();
	else if (argc >= 2)
	{
		if (argc == 4)
			init_params(&vars, argv[2], argv[3]);
		else
			set_complex(&vars.params.c, -0.6, 0.4);
		vars.mlx = mlx_init();
		if (!vars.mlx)
			error(ERROR_MLX);
		vars.win = mlx_new_window(vars.mlx, W, H, argv[1]);
		if (!vars.win)
			error(ERROR_WIN);
		choose_fract(&vars, argv[1]);
		draw_fractal(&vars, 1, W / 2, H / 2);
		mlx_hook(vars.win, 2, 0, key_hook, &vars);
		mlx_hook(vars.win, 4, 0, mouse_hook, &vars);
		mlx_hook(vars.win, 17, 0, close_crest, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
