/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:16:27 by aakhtab           #+#    #+#             */
/*   Updated: 2023/07/29 21:51:25 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	calculation(char *str, float res, int i)
{
	int	j;

	if (str[i] == '.')
	{
		i++;
		j = i;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				exit_error();
			res = res * 10 + str[i] - '0';
			i++;
		}
		i = i - j;
		while (i-- > 0)
			res /= 10;
	}
	return (res);
}

float	ft_atof(char *str)
{
	float	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		exit_error();
	while (str[i] && str[i] != '.')
	{
		if (!ft_isdigit(str[i]))
			exit_error();
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = calculation(str, res, i);
	return (res * sign);
}
