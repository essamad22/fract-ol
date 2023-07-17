/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab < aakhtab@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:10:19 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/17 17:54:33 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help(void)
{
	ft_putstr_fd("Usage: ./fractol [fractol_name]\n", 2);
	ft_putstr_fd("\nYou can specify fractal name from your choice!\n", 2);
	ft_putstr_fd("\nAvailable fractals:\n", 2);
	ft_putstr_fd("[	- Mandelbrot		]\n", 2);
	ft_putstr_fd("[	- Julia			]\n", 2);
	ft_putstr_fd("[	- Burning Ship		]\n", 2);
}

int check_fractal_name(char *name)
{
    if (!ft_strncmp(name, "Mandelbrot", 10))
        return (1);
    else if (!ft_strncmp(name, "Julia", 5))
        return (2);
    else if (!ft_strncmp(name, "Burning Ship", 12))
        return (3);
    else
    {
        ft_putstr_fd("Error: Invalid fractal name!\n", 2);
        ft_help();
        exit(1);
    }
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		fractal;

	if (ac != 2)
	{
		ft_help();
		return (1);
	}
	fractal = check_fractal_name(av[1]);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FRACTOL");
	draw(&mlx, fractal);
    mlx_hook(mlx.mlx_win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
}
