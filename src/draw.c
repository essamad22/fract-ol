/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab < aakhtab@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:49:11 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/16 12:11:39 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_mlx *mlx)
{
	t_data		img;
	t_fractol	fractol;

	img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        &img.endian);
	fractol.x = 0;
	while (fractol.x < WIDTH)
	{
		fractol.y = 0;
		while (fractol.y < HEIGHT)
		{
			my_mlx_pixel_put(&img, fractol.x, fractol.y, 0x00FF0000);
			fractol.y++;
		}
		fractol.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.img, 0, 0);
	// mlx_loop(mlx->mlx);
}
