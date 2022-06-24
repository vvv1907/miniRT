/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:13:45 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 17:19:12 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_alight(t_alight *alight)
{
	printf("****Ambient light****\n");
	printf("light range: %.1f\n", alight->light_range);
	printf("color: %d,%d,%d\n", alight->color.r, alight->color.g, alight->color.b);
	printf("*********************\n");
}
