/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoreen <lcoreen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:11:24 by lcoreen           #+#    #+#             */
/*   Updated: 2021/11/22 14:41:47 by lcoreen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"
#include "errors.h"

void	help(void)
{
	printf("Choose fractal set:\n");
	printf("type /mandelbrot/ if you want to plot Mandelbrot set\n");
	printf("type /julia c1 c2/ if you want to plot Julia set with parameter ");
	printf("c = c1 + c2*i\n");
	printf("type /\"burning ship\"/ if you want to plot Burning Ship\n");
}

void	error(char *msg)
{
	printf("%s", msg);
	exit(1);
}
