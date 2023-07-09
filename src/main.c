/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:21:14 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/08 18:42:28 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int	main(void)
{
	// t_data	img;
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Fract-ol");
	mlx_loop(mlx);
}