/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:22:54 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/08 10:42:39 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, int x, int y, t_fract *f)
{
	if (key == M_ZOOM_IN)
	{
		f->o_x = (f->o_x + x / f->zoom) - (x / (f->zoom * ZOOM_MULT));
		f->o_y = (f->o_y + y / f->zoom) - (y / (f->zoom * ZOOM_MULT));
		f->zoom *= ZOOM_MULT;
	}
	else if (key == M_ZOOM_OUT)
	{
		f->o_x = (f->o_x + x / f->zoom) - (x / (f->zoom / ZOOM_MULT));
		f->o_y = (f->o_y + y / f->zoom) - (y / (f->zoom / ZOOM_MULT));
		f->zoom /= ZOOM_MULT;
	}
}

void	move(int key, t_fract *f)
{
	if (key == K_A || key == K_LEFT)
		f->o_x = ((f->o_x * f->zoom) - MOVE_MULT) / f->zoom;
	else if (key == K_W || key == K_UP)
		f->o_y = ((f->o_y * f->zoom) - MOVE_MULT) / f->zoom;
	else if (key == K_D || key == K_RIGHT)
		f->o_x = ((f->o_x * f->zoom) + MOVE_MULT) / f->zoom;
	else if (key == K_S || key == K_DOWN)
		f->o_y = ((f->o_y * f->zoom) + MOVE_MULT) / f->zoom;
}

void	shift(int key, t_fract *f)
{
	if (!f->c_x)
		f->c_x = 0;
	if (!f->c_y)
		f->c_y = 0;
	if (key == K_Y)
		f->c_x -= C_MULT;
	else if (key == K_X)
		f->c_x += C_MULT;
	else if (key == K_C)
		f->c_y -= C_MULT;
	else if (key == K_V)
		f->c_y += C_MULT;
}

int	get_mouse_input(int key, int x, int y, t_fract *f)
{
	if (key == M_ZOOM_IN || key == M_ZOOM_OUT)
		zoom(key, x, y, f);
	draw(f);
	return (0);
}

int	get_kb_input(int key, t_fract *f)
{
	move(key, f);
	shift(key, f);
	if (key == K_I)
		f->max_iter += ITER_MULT;
	if (key == K_J)
		f->max_iter = fmax(f->max_iter - ITER_MULT, 0);
	if (key == K_R)
	{
		f->base = rand_rgb();
		f->max = rand_rgb();
	}
	if (key == K_Q)
		f->shift = fmax(0, f->shift - SHIFT_MULT);
	else if (key == K_E)
		f->shift += SHIFT_MULT;
	if (key == K_SPC)
		init_fract(f, NULL);
	if (key == K_ESC)
	{
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	draw(f);
	return (0);
}
