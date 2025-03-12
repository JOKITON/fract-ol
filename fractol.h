/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:24:44 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/11/28 14:29:32 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// General libraries included

# include <math.h>
# include "miniLibX/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

// Macros for Returning Values

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

// Macros for Keywords

# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MAIN_ESC 53
# define REQ_RESIZE 25
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define W_KEY 13
# define S_KEY 1
# define RAN_MAX 42

// Macros for Height & Width

# define HEIGHT 1000
# define WIDTH 1000

// Declaration of Structures

typedef struct img
{
	void	*img;
	int		*add;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct math
{
	long double	initial_x;
	long double	initial_y;
	long double	mod_x;
	long double	mod_y;
	long double	color;
	int			i;
}	t_math;

typedef	struct plane
{
	double	x;
	double	y;
} t_plane;

typedef struct s_vars
{
	char	*fractal;
	void	*init;
	void	*win;
	t_img	img;
	t_math	math;
	t_plane plane;
}		t_mlx;

// Image & Fractol Setup

char	*fractol_check(char	*fractol, t_mlx	*argv);
void	crt_image(t_mlx	*l_i);
int		close2(t_mlx	*hook);

void 	initiate(t_mlx *l_i);
void	image_init(t_mlx	*img);

void 	julia_init(t_mlx *img);
void 	mandel_init(t_mlx *img);

void	term(t_mlx	*param);

// Functions for Mouse & Key Hooks

int		key_handle(int key_event, t_mlx	*vars);
void	mlx_phook(t_mlx	*hook);

int		mouse_place(int	x, int	y, t_mlx	*vars);
int		mouse_zoom(int mouse_event, int	x, int	y,t_mlx	*vars);

int		zoomin(int x, int y, t_mlx	*vars);
int		zoomout(int x, int y, t_mlx	*vars);

// Mathematical & Fractol related Functions

void	mandelbrot(int htzl, int vert, t_mlx	*mandel);
int		mandel_it(t_mlx *mandel, long double y, long double a, long double b);

void	julia(int htzl, int vert, t_mlx	*julia);
int		julia_it(double x, double y, t_mlx	*julia);


#endif