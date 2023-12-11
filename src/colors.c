/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:34:15 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/31 14:05:31 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_bits(t_fractol *f)
{
	f->bits_16 = 16;
	f->bits_8 = 8;
	f->bits_0 = 0;
}

void	swap_bits(t_fractol **fractol)
{
	int	tmp;

	tmp = (*fractol)->bits_16;
	(*fractol)->bits_16 = (*fractol)->bits_8;
	(*fractol)->bits_8 = (*fractol)->bits_0;
	(*fractol)->bits_0 = tmp;
}

unsigned int	get_color(int i, t_fractol *f)
{
	double			t;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	color = 0;
	t = (double)i / MAX_ITER;
	r = 9 * (1 - t) * pow(t, 3) * 255;
	g = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	b = 8.5 * pow((1 - t), 3) * t * 255;
	if (i < MAX_ITER)
		color = (r << f->bits_16) + (g << f->bits_8) + (b << f->bits_0);
	return (color);
}
