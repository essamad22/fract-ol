/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:34:15 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/28 15:44:06 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    set_bits(t_fractol *f)
{
    f->bits_16 = 16;
    f->bits_8 = 8;
    f->bits_0 = 0;
}

unsigned int    get_color(int i, t_fractol *f)
{
    unsigned int    color;
    unsigned int    r;
    unsigned int    g;
    unsigned int    b;
    double          t;

    color = 0;
    t = (double)i / MAX_ITER;
    r = 9 * (1 - t) * pow(t, 3) * 255;
    g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
    b = 8.5 * pow((1 - t), 3) * t * 255;
    if (i < MAX_ITER)
        color = (r << f->bits_16) + (g << f->bits_8) + (b << f->bits_0);
    return (color);
}