/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab < aakhtab@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:49:11 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/17 16:51:52 by aakhtab          ###   ########.fr       */
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

void	draw(t_mlx *mlx, int fractal)
{
    t_data		data;
    t_fractol	f;

    data.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
            &data.line_length, &data.endian);
    f.y = -1;
    while (++f.y < HEIGHT)
    {
        f.x = -1;
        while (++f.x < WIDTH)
        {
            f.c.re = 1.5 * (f.x - WIDTH / 2) / (0.5 * WIDTH);
            f.c.im = (f.y - HEIGHT / 2) / (0.5 * HEIGHT);
            f.z.re = 0;
            f.z.im = 0;
            if (fractal == 1)
                mandelbrot(&f, &data);
            // else if (fractal == 2)
            //     julia(&f, &data);
            // else if (fractal == 3)
            //     burning_ship(&f, &data);
        }
    }
    mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, data.img, 0, 0);
    mlx_destroy_image(mlx->mlx, data.img);
}
