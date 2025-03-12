/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:48:51 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/11/28 19:13:50 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handle(int key_event, t_mlx	*vars)
{
	ft_printf("[%d]\n", key_event);
	if (key_event == MAIN_ESC)
	{
		term(vars);
		exit(EXIT_SUCCESS);
	}
	else if (key_event == ARROW_LEFT)
		vars->math.initial_x += (vars->math.mod_x / 8);
	else if (key_event == ARROW_RIGHT)
		vars->math.initial_x -= (vars->math.mod_x / 8);
	else if (key_event == ARROW_UP)
		vars->math.initial_y += (vars->math.mod_y / 8);
	else if (key_event == ARROW_DOWN)
		vars->math.initial_y -= (vars->math.mod_y / 8);
	else if (key_event == W_KEY)
		zoomin(vars->plane.x, vars->plane.y, vars);
	else if (key_event == S_KEY)
		zoomout(vars->plane.x, vars->plane.y, vars);
	image_init(vars);
	mlx_put_image_to_window(vars->init, vars->win, vars->img.img, 0, 0);
	return (EXIT_SUCCESS);
}

int	mouse_zoom(int mouse_event, int x, int y, t_mlx	*vars)
{
	if (mouse_event == SCROLL_DOWN)
	{
		zoomin(x, y, vars);
	}
	else if (mouse_event == SCROLL_UP)
	{
		zoomout(x, y, vars);
	}
	return (EXIT_SUCCESS);
}

int	zoomin(int x, int y, t_mlx	*vars)
{
	ft_printf("x:[%d]\ny:[%d]\n", x, y);
	vars->math.mod_x /= pow(1.003, 70);
	vars->math.mod_y /= pow(1.003, 70);
	image_init(vars);
	mlx_put_image_to_window(vars->init, vars->win, vars->img.img, 0, 0);
	return (EXIT_SUCCESS);
}

int	zoomout(int x, int y, t_mlx	*vars)
{
	ft_printf("x:[%d]\ny:[%d]\n", x, y);
	vars->math.mod_x *= pow(1.003, 70);
	vars->math.mod_y *= pow(1.003, 70);
	image_init(vars);
	mlx_put_image_to_window(vars->init, vars->win, vars->img.img, 0, 0);
	return (EXIT_SUCCESS);
}

int	mouse_place(int x, int y, t_mlx	*vars)
{
	vars->plane.x = x;
	vars->plane.y = y;
	julia(0, 0, vars);
	mlx_put_image_to_window(vars->init, vars->win, vars->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
