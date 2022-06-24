/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:41:57 by marlean           #+#    #+#             */
/*   Updated: 2022/06/24 17:09:57 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

typedef struct s_scene t_scene;
typedef struct s_alight t_alight;

typedef struct s_parser
{
	int		file_fd;
	int		read_res;
	char	*line;
	char	**map;
}	t_parser;

//init_parser.c
void	init_parser(t_parser *pars);
void	init_scene(t_scene *scene);

//parser.c
void	read_file(t_parser *pars, char *arg);
void	fill_scene(t_parser *pars, t_scene *scene);
int		open_scene(int argc, char **argv, t_scene *scene);

// utils_parser.c
void	print_array(char **arr);
void	error_parser(char *str);
void	capital_valid(t_parser *pars);
void	obj_valid(t_parser *pars);

//fill_obj.c
void fill_a(char *str, t_alight *alight);
void fill_c(char *str, t_scene *scene);
void fill_l(char *str, t_scene *scene);

//utils_fill.c
double	ft_atof(const char *str);
#endif