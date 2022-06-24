/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:06:42 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 16:50:47 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_parser(t_parser *pars)
{
	pars->file_fd = 0;
	pars->read_res = 0;
	pars->line = NULL;
	pars->map = NULL;
}

void	init_scene(t_scene *scene)
{
	scene->alight.light_range = 0;
	scene->alight.color.r = 0;
	scene->alight.color.g = 0;
	scene->alight.color.b = 0;
	scene->camera.view_point.x = 0.00;
	scene->camera.view_point.y = 0.00;
	scene->camera.view_point.z = 0.00;
	scene->camera.orient_vector.x = 0.00;
	scene->camera.orient_vector.y = 0.00;
	scene->camera.orient_vector.z = 0.00;
	scene->camera.horiz_degrees = 0;
	scene->light.coord.x = 0.00;
	scene->light.coord.y = 0.00;
	scene->light.coord.z = 0.00;
	scene->light.bright = 0.00;
	scene->light.color.r = 0;
	scene->light.color.g = 0;
	scene->light.color.b = 0;
}
