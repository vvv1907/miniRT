/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:44:55 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 17:16:37 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../mlx_1/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "parser.h"

typedef struct s_color //ЦВЕТ
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_coord //КООРДИНАТЫ
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct s_alight //ОБЩЕЕ ОСВЕЩЕНИЕ
{
	double			light_range;
	struct s_color	color;
}	t_alight;

typedef struct s_camera //КАМЕРА
{
	struct s_coord	view_point;
	struct s_coord	orient_vector;
	int				horiz_degrees;
}	t_camera;

typedef struct s_light //НАПРАВЛЕННЫЙ СВЕТ
{
	struct s_coord	coord;
	double			bright;
	struct s_color	color;
}	t_light;

typedef struct s_scene //СТРУКТУРА С ОБЩИМ СВЕТОМ, КАМЕРОЙ, НАПРАВЛЕННЫМ СВЕТОМ
{
	struct s_alight	alight;
	struct s_camera	camera;
	struct s_light	light;
}	t_scene;

//print_structs.c
void	print_alight(t_alight *alight);

#endif