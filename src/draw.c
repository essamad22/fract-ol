/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:49:11 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/28 14:26:27 by aakhtab          ###   ########.fr       */
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

void	draw(t_fractol *f)
{
    // f->zoom = 1;
    f->z.re = 0;
    f->z.im = 0;
    f->y = -1;
    while (++f->y < HEIGHT)
    {
        f->x = -1;
        while (++f->x < WIDTH)
        {
            if (f->fractal == 1)
                mandelbrot(&f, &f->data);
            else if (f->fractal == 2)
                julia(&f, &f->data);
            else if (f->fractal == 3)
                burning_ship(&f, &f->data);
        }
    }
    mlx_put_image_to_window(f->mlx.mlx, f->mlx.mlx_win, f->data.img, 0, 0);
    // mlx_loop(f->mlx.mlx);
}
