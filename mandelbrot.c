/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:14:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/11/10 17:58:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandel_it(t_mlx *mandel, long double y, long double a, long double b)
{
	long double	t;
	long double	x;
	int			i;

	i = 0;
	x = 0.0;
	while (i <= mandel->math.i)
	{
		t = x;
		x = (x * x) - (y * y) + a;
		y = (2 * t * y) + b;
		if (((x * x) + (y * y)) > 4)
			break ;
		i++;
	}
	return (i);
}

void	mandelbrot(int hztl, int vert, t_mlx	*mandel)
{
	mlx_clear_window(mandel->init, mandel->win);
	vert = 0;
	while (vert < HEIGHT)
	{
		hztl = 0;
		while (hztl < WIDTH)
		{
			mandel->img.add[(vert * WIDTH) + hztl] = mandel_it(mandel, 0,
					(((long double)hztl / WIDTH) - 0.5)
					* mandel->math.mod_x - mandel->math.initial_x,
					(((long double)vert / HEIGHT) - 0.5)
					*mandel->math.mod_y - mandel->math.initial_y)
				* mandel->math.color;
			hztl++;
		}
	vert++;
	}
	mlx_put_image_to_window(mandel->init, mandel->win, mandel->img.img, 0, 0);
}
