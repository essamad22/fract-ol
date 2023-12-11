/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:49 by aakhtab           #+#    #+#             */
/*   Updated: 2023/12/11 14:27:16 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 460
# define HEIGHT 420
# define MAX_ITER 30
// ----- macOS keyboard -----
# define MAIN_PAD_ESC 53
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
// ----- Linux keyboard -----
# define ESC_L 65307
# define ARROW_UP_L 65362
# define ARROW_DOWN_L 65364
# define ARROW_LEFT_L 65361
# define ARROW_RIGHT_L 65363
# define C_KEY_L 99
# define SPACE_KEY_L 32
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
}					t_mlx;

typedef struct s_complex
{
	float			re;
	float			im;
}					t_complex;

typedef struct s_fractol
{
	t_mlx			mlx;
	t_data			data;
	float			j_re;
	float			j_im;
	t_complex		c;
	t_complex		z;
	float			x;
	float			y;
	int				fractal;
	unsigned int	color;
	float			zoom;
	int				bits_16;
	int				bits_8;
	int				bits_0;

}					t_fractol;

void				draw(t_fractol *f);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				mandelbrot(t_fractol **f, t_data *data);
void				julia(t_fractol **f, t_data *data);
unsigned int		get_color(int i, t_fractol *f);
int					key_press(int key, t_fractol *fractol);
int					mouse_press(int key, int x, int y, t_fractol *fractol);
float				ft_atof(char *str);
int					close_window(void);
void				burning_ship(t_fractol **f, t_data *data);
void				set_bits(t_fractol *f);
void				swap_bits(t_fractol **fractol);
void				exit_error(void);
#endif
