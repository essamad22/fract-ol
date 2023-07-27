/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:10:19 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/27 11:16:50 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help(void)
{
	ft_putstr_fd("Usage: ./fractol [fractol_name] [julia_c(julia-only)]\n", 2);
	ft_putstr_fd("\nYou can specify fractal name from your choice!\n", 2);
	ft_putstr_fd("\nAvailable fractals:\n", 2);
	ft_putstr_fd("[	- Mandelbrot		]\n", 2);
	ft_putstr_fd("[	- Julia			]\n", 2);
	ft_putstr_fd("[	- Burning Ship		]\n", 2);
	ft_putstr_fd("\nExample: ./fractol Mandelbrot\n", 2);
}

int 	init_fractol(int ac, char **av, t_fractol *f)
{
	char    *name;

	name = av[1];
    if (!ft_strncmp(name, "Mandelbrot", 10))
	{
		if (ac != 2)
		{
			ft_help();
			exit(1);
		}
        return (1);
	}
    else if (!ft_strncmp(name, "Julia", 5))
	{
		if (ac != 4)
		{
			ft_help();
			exit(1);
		}
		f->j_re = ft_atof(av[2]);
		f->j_im = ft_atof(av[3]);
        return (2);
	}
    else if (!ft_strncmp(name, "Burning Ship", 12))
	{
		if (ac != 2)
		{
			ft_help();
			exit(1);
		}
        return (3);
	}
    else
    {
        ft_putstr_fd("Error: Invalid fractal name!\n", 2);
        ft_help();
        exit(1);
    }
	
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
	{
		ft_help();
		exit(1);
	}
	f.fractal = init_fractol(ac, av, &f);
	f.mlx.mlx = mlx_init();
	f.mlx.mlx_win = mlx_new_window(f.mlx.mlx, WIDTH, HEIGHT, "FRACTOL");
	f.data.img = mlx_new_image(f.mlx.mlx, WIDTH, HEIGHT);
	f.data.addr = mlx_get_data_addr(f.data.img, &f.data.bits_per_pixel, 
		&f.data.line_length, &f.data.endian);
	mlx_hook(f.mlx.mlx_win, 2, 0, key_press, &f);
    mlx_hook(f.mlx.mlx_win, 17, 0, close_window, &f);
	f.zoom = 1;
	draw(&f);
	mlx_loop(f.mlx.mlx);
}
