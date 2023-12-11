/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:18:52 by aakhtab           #+#    #+#             */
/*   Updated: 2023/12/11 15:18:07 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_sets(int key, t_fractol **fractol)
{
	if (key == 13 || key == W_KEY)
		(*fractol)->j_im += 0.015;
	else if (key == 1 || key == S_KEY)
		(*fractol)->j_im -= 0.015;
	else if (key == 0 || key == A_KEY)
		(*fractol)->j_re -= 0.015;
	else if (key == 2 || key == D_KEY)
		(*fractol)->j_re += 0.015;
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC || key == ESC_L)
		exit(0);
	else if (key == 8 || key == C_KEY_L)
		swap_bits(&fractol);
	else if (key == 49 || key == SPACE_KEY_L)
	{
		fractol->zoom = 1;
		fractol->fractal++;
		if (fractol->fractal == 2)
		{
			fractol->j_re = -1;
			fractol->j_im = 0;
		}
		else if (fractol->fractal > 3)
			fractol->fractal = 1;
	}
	else if ((key == 1 || key == 0 || key == 2 || key == 13
        || key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
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
		if (fractol->zoom >= 0.000001)
			fractol->zoom *= 0.85;
	}
	draw(fractol);
	return (0);
}

int	close_window(void)
{
	exit(0);
}
