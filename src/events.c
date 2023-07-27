/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:18:52 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/27 14:42:15 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_press(int key, t_fractol *fractol)
{
    // (void)fractol;
    // fractol->zoom = 1;
	if (key == MAIN_PAD_ESC)
		exit(0);
    else if (key == ARROW_UP)
        fractol->zoom *= 1.15;
    else if (key == ARROW_DOWN)
        fractol->zoom *= 0.15;
    printf("zoom: %f\n", fractol->zoom);
    draw(fractol);
    return (0);
}

int mouse_press(int key, int x, int y, t_fractol *fractol)
{
    (void)x;
    (void)y;
    if (key == MOUSE_SCROLL_UP)
    {
        
    }
    else if (key == MOUSE_SCROLL_DOWN)
    {
        fractol->zoom -= 0.5;
        fractol->x = 0;
        fractol->y = 0;
    }
    return (0);
}

int close_window(void)
{
	exit(0);
}