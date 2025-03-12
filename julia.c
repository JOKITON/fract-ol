/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:16:25 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/11/28 19:12:53 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_it(double x, double y, t_mlx	*julia)
{
	int		i;
	double	t;
	double	a;
	double	b;

	i = 1;
	a = (julia->plane.x / 1000.0 - 0.5) * (double) 4 ;
	b = (julia->plane.y / 1000.0 - 0.5) * (double) 4;
	while (i <= julia->math.i)
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

void	julia(int hztl, int vert, t_mlx	*julia)
{
	mlx_clear_window(julia->init, julia->win);
	vert = 0;
	while (vert < HEIGHT)
	{
		hztl = 0;
		while (hztl < WIDTH)
		{
			julia->img.add[(vert * WIDTH) + hztl] = julia_it(
					(((long double)hztl / WIDTH) - 0.5)
					* julia->math.mod_x - julia->math.initial_x,
					(((long double)vert / HEIGHT) - 0.5)
					*julia->math.mod_y - julia->math.initial_y, julia)
				* julia->math.color;
			hztl++;
		}
	vert++;
	}
	mlx_put_image_to_window(julia->init, julia->win, julia->img.img, 0, 0);
}
