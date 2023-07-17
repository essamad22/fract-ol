/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab < aakhtab@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:10:19 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/17 01:16:20 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./fractol [fractol_name]\n", 2);
		return (1);
	}
	t_mlx mlx;
	
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "FRACTOL");
	draw(&mlx);
	mlx_loop(mlx.mlx);
	// close_window(&mlx);
}
