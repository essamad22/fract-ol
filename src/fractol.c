/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:10:19 by aakhtab           #+#    #+#             */
/*   Updated: 2023/12/11 11:40:57 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help(void)
{
	ft_putstr_fd("Usage: ./fractol [fractol_name] [julia re] [julia im]\n", 2);
	ft_putstr_fd("\nYou can specify fractal name from your choice!\n", 2);
	ft_putstr_fd("\nAvailable fractals:\n", 2);
	ft_putstr_fd("[	- Mandelbrot		]\n", 2);
	ft_putstr_fd("[	- Julia			]\n", 2);
	ft_putstr_fd("[	- Burning Ship		]\n", 2);
	ft_putstr_fd("\nYou can specify julia parameters!\n", 2);
	ft_putstr_fd("\n!!! Valid julia parameters: between 2 & -2\n", 2);
	ft_putstr_fd("\nSOME FEATURES:\n", 2);
	ft_putstr_fd("\nYou can change re & im of julia with this bottons :\n", 2);
	ft_putstr_fd("[ [W] - [S] - [A] - [D] ]\n", 2);
	ft_putstr_fd("\nYou can also change between fractals with space\n", 2);
	ft_putstr_fd("\nYou can zoom in & out with mouse wheel\n", 2);
	ft_putstr_fd("\nYou can change colors with this botton : [C]\n", 2);
	ft_putstr_fd("\nExampels:\n./fractol Mandelbrot\n", 2);
	ft_putstr_fd("./fractol Julia -0.4 0.6\n", 2);
	ft_putstr_fd("./fractol [Burning Ship]\n", 2);
}

void	exit_error(void)
{
	ft_help();
	exit(0);
}

void	julia_param(t_fractol **f, char *real, char *imaginary)
{
	(*f)->j_re = ft_atof(real);
	(*f)->j_im = ft_atof(imaginary);
	if ((*f)->j_re < -2 || (*f)->j_re > 2 || (*f)->j_im < -2 || (*f)->j_im > 2)
		exit_error();
}

int	init_fractol(int ac, char **av, t_fractol *f)
{
	if (!ft_strncmp(av[1], "Mandelbrot", 11))
	{
		if (ac != 2)
			exit_error();
		return (1);
	}
	else if (!ft_strncmp(av[1], "Julia", 6))
	{
		if (ac != 4)
			exit_error();
		julia_param(&f, av[2], av[3]);
		return (2);
	}
	else if (!ft_strncmp(av[1], "Burning Ship", 13))
	{
		if (ac != 2)
			exit_error();
		return (3);
	}
	else
	{
		exit_error();
		return (0);
	}
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
		exit_error();
	f.fractal = init_fractol(ac, av, &f);
	f.mlx.mlx = mlx_init();
	f.mlx.mlx_win = mlx_new_window(f.mlx.mlx, WIDTH, HEIGHT, "FRACTOL");
	f.data.img = mlx_new_image(f.mlx.mlx, WIDTH, HEIGHT);
	f.data.addr = mlx_get_data_addr(f.data.img, &f.data.bits_per_pixel,
			&f.data.line_length, &f.data.endian);
	mlx_hook(f.mlx.mlx_win, 2, 1L<<0, key_press, &f);
	mlx_mouse_hook(f.mlx.mlx_win, mouse_press, &f);
	mlx_hook(f.mlx.mlx_win, 17, 0, close_window, &f);
	f.zoom = 1;
	set_bits(&f);
	draw(&f);
	mlx_loop(f.mlx.mlx);
}
