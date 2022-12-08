/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:28:03 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/07 22:53:22 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(int x, int y, t_fract *f)
{
	double	c_x;
	double	c_y;
	double	z_x;
	double	z_y;
	int		ret;

	c_x = f->c_x;
	c_y = f->c_y;
	z_x = f->o_x + x / f->zoom;
	z_y = f->o_y + y / f->zoom;
	ret = 0;
	while (sqrt(pow(z_x, 2) + pow(z_y, 2)) < 2 && ret < f->max_iter)
	{
		f->tmp = z_x;
		z_x = pow(z_x, 2) - pow(z_y, 2) + c_x;
		z_y = 2 * f->tmp * z_y + c_y;
		++ret;
	}
	return (ret);
}

void	draw_julia(t_fract *f)
{
	int	x;
	int	y;
	int	iter;
	int	colour;

	f->img = mlx_new_image(f->mlx, WIN_X, WIN_Y);
	f->data = mlx_get_data_addr(f->img, &f->bpp, &f->sl, &f->end);
	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y)
		{
			iter = julia(x, y, f);
			colour = get_colour(f->base, f->max,
					((double) iter) / f->max_iter, f->shift);
			ft_memcpy(f->data + x * f->bpp
				/ 8 + y * f->sl, &colour, sizeof(int));
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
}

void	init_julia(t_fract *f)
{
	f->o_x = -3;
	f->o_y = -2;
	f->zoom = 300;
	f->max_iter = 100;
	f->shift = 1;
	f->base = itorgb(0x123456);
	f->max = itorgb(0xABCDEF);
	f->c_x = -0.7269;
	f->c_y = 0.1889;
}
