/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:58:48 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 17:24:15 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	read_file(t_parser *pars, char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (ft_strncmp(&arg[len - 3], ".rt", 3))
		error_parser("You are trying to open file, which is not .rt");
	pars->file_fd = open(arg, O_RDONLY);
	if (pars->file_fd == -1)
		error_parser("Can not open this file");
	pars->read_res = gnl_fd(&pars->line, pars->file_fd);
	if (pars->read_res <= 0)
		error_parser("Can not read this file");
	pars->map = ft_split(pars->line, '\n');
	free(pars->line);
	if (pars->map == NULL)
		error_parser("Empty file");
}

void	fill_scene(t_parser *pars, t_scene *scene)
{
	int	i;

	i = 0;
	while(pars->map[i])
	{
		if (pars->map[i][0] == 'A')
			fill_a(pars->map[i], &scene->alight);
		else if (pars->map[i][0] == 'C')
			fill_c(pars->map[i], scene);
		else if (pars->map[i][0] == 'L')
			fill_l(pars->map[i], scene);
		i++;
	}
	print_alight(&scene->alight);
}

int	open_scene(int argc, char **argv, t_scene *scene)
{
	t_parser	pars;

	init_parser(&pars);
	if (argc != 2)
		error_parser("Wrong number of arguments");
	read_file(&pars, argv[1]);
	capital_valid(&pars);
	obj_valid(&pars);
	fill_scene(&pars, scene);
	printf("arg: %s\n", argv[1]);
	return (0);
}
