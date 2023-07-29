/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:18:52 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/28 22:43:40 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	swap_bits(t_fractol **fractol)
{
	int	tmp;

	tmp = (*fractol)->bits_16;
	(*fractol)->bits_16 = (*fractol)->bits_8;
	(*fractol)->bits_8 = (*fractol)->bits_0;
	(*fractol)->bits_0 = tmp;
}

void	julia_sets(int key, t_fractol **fractol)
{
	if (key == ARROW_UP)
		(*fractol)->j_im += 0.025;
	else if (key == ARROW_DOWN)
		(*fractol)->j_im -= 0.025;
	else if (key == ARROW_LEFT)
		(*fractol)->j_re -= 0.025;
	else if (key == ARROW_RIGHT)
		(*fractol)->j_re += 0.025;
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == 8)
		swap_bits(&fractol);
	else if (key == 49)
	{
		fractol->fractal++;
		if (fractol->fractal == 2)
		{
			fractol->j_re = 0.285;
			fractol->j_im = 0.01;
		}
		else if (fractol->fractal > 3)
			fractol->fractal = 1;
	}
	else if ((key == 124 || key == 123 || key == 126 || key == 125)
		&& fractol->fractal == 2)
		julia_sets(key, &fractol);
	draw(fractol);
	return (0);
}

int	mouse_press(int key, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (key == 5)
		fractol->zoom *= 1.17647058823;
	else if (key == 4)
	{
		if (fractol->zoom >= 0.001)
			fractol->zoom *= 0.85;
	}
	draw(fractol);
	return (0);
}

int	close_window(void)
{
	exit(0);
}
