/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:34:15 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/25 12:55:24 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int    get_color(int i)
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
        color = (r << 16) + (g << 8) + b;
    return (color);
}