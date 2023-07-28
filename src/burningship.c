/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:04:13 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/28 21:58:25 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship(t_fractol **f, t_data *data)
{
	int     i;
	double  tmp;

	(*f)->c.re = 1.75 * ((*f)->x - WIDTH / 2) / (WIDTH / 2) / (*f)->zoom;
	(*f)->c.im = 1.25 * ((*f)->y - HEIGHT / 2) / (HEIGHT / 2) / (*f)->zoom;
	(*f)->z.re = 0;
	(*f)->z.im = 0;
	i = 0;
	while (pow((*f)->z.re, 2.0) + pow((*f)->z.im, 2.0) < 4 && i < MAX_ITER)
	{
		tmp = (*f)->z.re;
		(*f)->z.re = pow((*f)->z.re, 2.0) - pow((*f)->z.im, 2.0) + (*f)->c.re;
		(*f)->z.im = 2 * fabs((*f)->z.im) * fabs(tmp) + (*f)->c.im;
		i++;
	}
	(*f)->color = get_color(i, (*f));
	if (i == MAX_ITER)
		my_mlx_pixel_put(data, (*f)->x, (*f)->y, 0x000000);
	else
		my_mlx_pixel_put(data, (*f)->x, (*f)->y, (*f)->color);
}