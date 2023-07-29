/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:52:24 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/28 23:39:49 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol **f, t_data *data)
{
	int		i;
	double	tmp;

	i = -1;
	(*f)->c.re = 2 * ((*f)->x - WIDTH / 2) / (WIDTH / 2) / (*f)->zoom;
	(*f)->c.im = 1.5 * ((*f)->y - HEIGHT / 2) / (HEIGHT / 2) / (*f)->zoom;
	(*f)->z.re = 0;
	(*f)->z.im = 0;
	while (++i < MAX_ITER)
	{
		tmp = (*f)->z.re;
		(*f)->z.re = pow((*f)->z.re, 2.0) - pow((*f)->z.im, 2.0) + (*f)->c.re;
		(*f)->z.im = 2 * (*f)->z.im * tmp + (*f)->c.im;
		if (pow((*f)->z.re, 2.0) + pow((*f)->z.im, 2.0) > 4)
			break ;
	}
	(*f)->color = get_color(i, (*f));
	if (i == MAX_ITER)
		my_mlx_pixel_put(data, (*f)->x, (*f)->y, 0x000000);
	else
		my_mlx_pixel_put(data, (*f)->x, (*f)->y, (*f)->color);
}
