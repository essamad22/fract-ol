/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:49 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/27 11:30:09 by aakhtab          ###   ########.fr       */
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

# define WIDTH 550
# define HEIGHT 500
# define MAX_ITER 40

# define MAIN_PAD_ESC		53
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define ARROW_UP			126
# define ARROW_DOWN			125

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
	float		re;
	float		im;
}				t_complex;

typedef struct s_fractol
{
	t_mlx		mlx;
	t_data		data;
	float		j_re;
	float		j_im;
	t_complex	c;
	t_complex	z;
	float		x;
	float		y;
	int 		fractal;
    unsigned int color;
	float		zoom;
	int 		test;
}				t_fractol;

void    		draw(t_fractol *f);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    		mandelbrot(t_fractol **f, t_data *data);
void    		julia(t_fractol **f, t_data *data);
unsigned int	get_color(int i);
int 			key_press(int key, t_fractol *fractol);
int 			mouse_press(int key, int x, int y, t_fractol *fractol);
float	  		ft_atof(char *str);
int 			close_window(void);
// void    burning_ship(t_fractol *f, t_data *data);
#endif
