/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:51:38 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/11/28 19:14:32 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_phook(t_mlx	*hook)
{
	mlx_hook(hook->win, 2, (1L << 0), key_handle, hook);
	mlx_hook(hook->win, 17, 0, close2, hook);
	mlx_hook(hook->win, 4, (1L << 2), mouse_zoom, hook);
	if (ft_strnstr(hook->fractal, "julia", 5))
	{
		mlx_hook(hook->win, 6, (1L << 6), mouse_place, hook);
	}
	mlx_loop(hook->init);
}

void	mandel_init(t_mlx *img)
{
	img->math.initial_x = 0;
	img->math.initial_y = 0;
	img->math.mod_x = 4;
	img->math.mod_y = 4;
	img->math.color = 6200;
	if (!img->math.i)
		img->math.i = 250;
}

void	julia_init(t_mlx *img)
{
	img->math.initial_x = 0;
	img->math.initial_y = 0;
	img->math.mod_x = 4;
	img->math.mod_y = 4;
	img->math.color = 6200;
	if (!img->math.i)
		img->math.i = 150;
}

void	crt_image(t_mlx	*img)
{
	if (ft_strnstr(img->fractal, "mandelbrot", 10))
	{
		mandel_init(img);
		mandelbrot(0, 0, img);
	}
	else if (ft_strnstr(img->fractal, "julia", 5))
	{
		julia_init(img);
		julia(0, 0, img);
	}
	mlx_put_image_to_window(img->init, img->win, img->img.img, 0, 0);
}

void	image_init(t_mlx	*img)
{
	if (ft_strnstr(img->fractal, "mandelbrot", 10))
		mandelbrot(0, 0, img);
	else if (ft_strnstr(img->fractal, "julia", 5))
		julia(0, 0, img);
	mlx_put_image_to_window(img->init, img->win, img->img.img, 0, 0);
}
