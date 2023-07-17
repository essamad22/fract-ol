/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab < aakhtab@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:34:15 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/17 16:51:12 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    mandelbrot(t_fractol *f, t_data *data)
{
    int     i;
    double  tmp;

    i = -1;
    while (++i < MAX_ITER)
    {
        tmp = f->z.re;
        f->z.re = f->z.re * f->z.re - f->z.im * f->z.im + f->c.re;
        f->z.im = 2 * f->z.im * tmp + f->c.im;
        if ((f->z.re * f->z.re + f->z.im * f->z.im) > 4)
            break ;
    }
    if (i == MAX_ITER)
        my_mlx_pixel_put(data, f->x, f->y, 0x000000);
    else
        my_mlx_pixel_put(data, f->x, f->y, i * 0x00AABF00);
}