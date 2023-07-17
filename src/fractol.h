/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab < aakhtab@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:49 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/17 16:53:09 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1330
# define HEIGHT 800
# define MAX_ITER 40

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
}				t_mlx;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_fractol
{
	t_complex	c;
	t_complex	z;
	double		x;
	double		y;
}				t_fractol;

void    draw(t_mlx *mlx, int fractal);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    mandelbrot(t_fractol *f, t_data *data);
void    julia(t_fractol *f, t_data *data);
#endif
