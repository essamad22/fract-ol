/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:51:47 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/28 15:45:08 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    julia(t_fractol **f, t_data *data)
{
    int     i;
    float  tmp;
    
    (*f)->z.re = 2 * ((*f)->x - WIDTH / 2) / (WIDTH / 2) / (*f)->zoom;
    (*f)->z.im = 1.5 * ((*f)->y - HEIGHT / 2) / (HEIGHT / 2) / (*f)->zoom;
    i = -1;
    while (++i < MAX_ITER)
    {
        tmp = (*f)->z.re;
        (*f)->z.re = pow((*f)->z.re, 2.0) - pow((*f)->z.im, 2.0) + (*f)->j_re;
        (*f)->z.im = 2 * (*f)->z.im * tmp + (*f)->j_im;
        if (pow((*f)->z.re, 2.0) + pow((*f)->z.im, 2.0) > 4)
            break ;
    }
    (*f)->color = get_color(i, (*f));
    if (i == MAX_ITER)
        my_mlx_pixel_put(data, (*f)->x, (*f)->y, 0x000000);
    else
        my_mlx_pixel_put(data, (*f)->x, (*f)->y, (*f)->color);
}