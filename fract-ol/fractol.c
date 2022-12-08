/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprahin <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:22:21 by aprahin           #+#    #+#             */
/*   Updated: 2022/12/08 10:57:01 by aprahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_fractal(char *str)
{
	if (!str)
		return (-1);
	if (ft_strncmp("mandelbrot", str, 11) == 0)
		return (0);
	if (ft_strncmp("julia", str, 6) == 0)
		return (1);
	if (ft_strncmp("burningship", str, 12) == 0)
		return (2);
	return (-1);
}

int	parse_args(char **argv)
{
	int		ret;
	char	*tmp;
	char	*input;

	ret = get_fractal(argv[1]);
	if (ret >= 0)
		return (ret);
	else
	{
		while (ret < 0)
		{
			ft_printf("Please choose a valid fractal:\n\n - mandelbrot \
			\n - julia\n - burningship\n\n>");
			tmp = get_next_line(STDIN_FILENO);
			input = ft_strtrim(tmp, "\n");
			free(tmp);
			ret = get_fractal(input);
			free(input);
		}
		return (ret);
	}
}

void	init_fract(t_fract *f, char **argv)
{
	if (f->type == 0)
		init_mb(f);
	else if (f->type == 1)
	{
		init_julia(f);
		if (argv && argv[2] && argv[3])
		{
			f->c_x = 0.0;
			f->c_y = 0.0;
			if (ft_strchr(argv[2], '.'))
				f->c_x = ((double) ft_atoi(ft_strchr(argv[2], '.') + 1))
					/ pow(10, ft_strlen(ft_strchr(argv[2], '.') + 1));
			if (ft_strchr(argv[3], '.'))
				f->c_y = ((double) ft_atoi(ft_strchr(argv[3], '.') + 1))
					/ pow(10, ft_strlen(ft_strchr(argv[3], '.') + 1));
			f->c_x += abs(ft_atoi(argv[2]));
			f->c_y += abs(ft_atoi(argv[3]));
			if (ft_atoi(argv[2]) < 0)
				f->c_x *= -1;
			if (ft_atoi(argv[3]) < 0)
				f->c_y *= -1;
		}
	}
	else if (f->type == 2)
		init_bs(f);
}

void	draw(t_fract *f)
{
	if (f->type == 0)
		draw_mb(f);
	else if (f->type == 1)
		draw_julia(f);
	else if (f->type == 2)
		draw_bs(f);
}

int	main(int argc, char **argv)
{
	t_fract	fractol;

	(void) argc;
	fractol.type = parse_args(argv);
	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		return (1);
	fractol.win = mlx_new_window(fractol.mlx, WIN_X, WIN_Y, "fract-ol");
	if (!fractol.win)
		return (2);
	init_fract(&fractol, argv);
	draw(&fractol);
	if (!mlx_key_hook(fractol.win, &get_kb_input, &fractol)
		|| !mlx_mouse_hook(fractol.win, &get_mouse_input, &fractol)
		|| !mlx_hook(fractol.win, 17, 0, &close_mlx, &fractol))
		return (3);
	mlx_loop(fractol.mlx);
	return (4);
}
