/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:12:41 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/11/28 19:10:04 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	term(t_mlx	*param)
{
	(void)param;
	exit(EXIT_FAILURE);
}

int	close2(t_mlx	*hook)
{
	(void)hook;
	exit(EXIT_SUCCESS);
}

void	check_args(t_mlx	*mlx, char	**argv, int args)
{
	if (args < 2)
	{
		write(1, "Not enough parameters for the program to work!\n", 48);
		write(1, "Format: ./fractol 'fractal' 'iterations'\n", 41);
		term(mlx);
	}
	else if (!fractol_check(argv[1], mlx))
	{
		write(1, "The fractol you have entered does not exist!\n", 45);
		write(1, "Fractals available:\n1.Mandelbrot.\n2.Julia\n", 42);
		term(mlx);
	}
	else if (args == 3)
		mlx->math.i = ft_atoi(argv[2]);
}

char	*fractol_check(char	*fractol, t_mlx	*argv)
{
	if (ft_strnstr(fractol, "mandelbrot", 10))
	{
		argv->fractal = "mandelbrot";
		return ("EXIT_SUCCESS");
	}
	else if (ft_strnstr(fractol, "julia", 5))
	{
		argv->fractal = "julia";
		return ("EXIT_SUCCESS");
	}
	else
		return (NULL);
}

int	main(int args, char	**argv)
{
	t_mlx		mlx;

	check_args(&mlx, argv, args);
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, HEIGHT, WIDTH, "Hello World!");
	mlx.img.img = mlx_new_image(mlx.init, HEIGHT, WIDTH);
	mlx.img.add = (int *)mlx_get_data_addr(mlx.img.img,
			&mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	crt_image(&mlx);
	mlx_phook(&mlx);
	return (EXIT_SUCCESS);
}
