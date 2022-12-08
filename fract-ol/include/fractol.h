/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:24:48 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/08 10:49:19 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <math.h>
# include "mlx.h"

// open
# include <fcntl.h>

// close, read, write, exit
# include <unistd.h>

// malloc, free
# include <stdlib.h>

// perror
# include <stdio.h>

// strerror
# include <string.h>

# define WIN_X		1440
# define WIN_Y		810
# define M_ZOOM_IN	5
# define M_ZOOM_OUT	4
# define ZOOM_MULT	1.5
# define MOVE_MULT	50
# define SHIFT_MULT 0.1
# define C_MULT		0.05
# define ITER_MULT	3

/*# define K_LEFT		65361
# define K_UP		65362
# define K_RIGHT	65363
# define K_DOWN		65364

# define K_I		105
# define K_J		106
# define K_A		97
# define K_W		119
# define K_S		115
# define K_D		100
# define K_R		114
# define K_Q		113
# define K_E		101
# define K_Y		121
# define K_X		120
# define K_C		99
# define K_V		118
# define K_SPC		32
# define K_ESC		65307*/
# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_LEFT 123
# define K_RIGHT 124
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_P 35
# define K_R 15
# define K_U 32
# define K_J 38
# define K_I 34
# define K_K 40
# define K_O 31
# define K_L 37
# define K_SPC 49
# define K_Y 6
# define K_X 7
# define K_C 8
# define K_V 9
# define K_Q 12
# define K_E 14

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_fract {
	void	*mlx;
	void	*win;
	void	*img;
	void	*data;
	int		type;
	int		bpp;
	int		sl;
	int		end;
	int		max_iter;
	double	zoom;
	double	o_x;
	double	o_y;
	double	c_x;
	double	c_y;
	double	shift;
	double	tmp;
	t_rgb	base;
	t_rgb	max;
}	t_fract;

// fractol.c
int		get_fractal(char *str);
int		parse_args(char **argv);
void	draw(t_fract *f);
void	init_fract(t_fract *f, char **argv);

// colours.c
t_rgb	rand_rgb(void);
int		hue_mod(double val);
t_rgb	itorgb(int colour);
int		get_colour(t_rgb base, t_rgb max, double ratio, double shift);

// mandelbrot.c
int		mandelbrot(int x, int y, t_fract *f);
void	draw_mb(t_fract *f);
void	init_mb(t_fract *f);
int		close_mlx(t_fract *f);

// julia.c
int		julia(int x, int y, t_fract *f);
void	draw_julia(t_fract *f);
void	init_julia(t_fract *f);

// burningship.c
int		burningship(int x, int y, t_fract *f);
void	draw_bs(t_fract *f);
void	init_bs(t_fract *f);

// events.c
void	zoom(int key, int x, int y, t_fract *f);
void	move(int key, t_fract *f);
void	shift(int key, t_fract *f);
int		get_mouse_input(int key, int x, int y, t_fract *f);
int		get_kb_input(int key, t_fract *f);

#endif