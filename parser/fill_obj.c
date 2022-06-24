/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:24:43 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 17:30:46 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void fill_a(char *str, t_alight *alight)
{
	int	i;

	i = 1;
	while(ft_isspace(str[i]))
		i++;
	alight->light_range = ft_atof(&str[i]);
	if (alight->light_range < 0.0f || alight->light_range > 1.0f)
		error_parser("Ambient lighting ratio not in range 0.0 - 1.0");
	while(!ft_isspace(str[i]))
		i++;
	while(ft_isspace(str[i]))
		i++;
	alight->color.r = ft_atoi(&str[i]);
	while(str[i] != ',')
		i++;
	i++;
	alight->color.g = ft_atoi(&str[i]);
	while(str[i] != ',')
		i++;
	i++;
	alight->color.b = ft_atoi(&str[i]);
	if (alight->color.r < 0 || alight->color.r > 255 || 
		alight->color.g < 0 || alight->color.g > 255 ||
		alight->color.b < 0 || alight->color.b > 255 )
		error_parser("R,G,B colors not in range 0-255");
}
void fill_c(char *str, t_scene *scene)
{
	(void)scene;
	printf("%s\n", str);
}
void fill_l(char *str, t_scene *scene)
{
	(void)scene;
	printf("%s\n", str);
}