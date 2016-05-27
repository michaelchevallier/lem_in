/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:55:44 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/26 14:56:35 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_ants(t_map **map, int i, int j)
{
	int		len;

	len = ft_strlen((*map)->cleanfile[i]);
	if (len == 0)
		ft_error("nb ants invalid 1");
	if ((*map)->cleanfile[i][j] != '#' &&
			(ft_isdigit((*map)->cleanfile[i][j] == 0) &&
				(*map)->cleanfile[i][j] != '+'))
		ft_error("nb ants invalid 2");
	else if ((*map)->cleanfile[i][j] == '#' && len > 2)
	{
		if ((*map)->cleanfile[i][j + 1] == '#')
			if (ft_strcmp(&(*map)->cleanfile[i][j + 2], "start") == 0 ||
					ft_strcmp(&(*map)->cleanfile[i][j + 2], "end") == 0)
				ft_error("nb ants invalid 3");
	}
	else
	{
		(*map)->nb_ants = ft_atoi((*map)->cleanfile[i]);
		(*map)->antindex = i;
		if ((*map)->nb_ants <= 0 || only_digit((*map)->cleanfile[i]) == 0)
				ft_error("nb ants invalid 4");
	}
}

void			matrix_duplicator(t_path **antpit)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((*antpit)->matrix[i] != NULL)
	{
		while ((*antpit)->matrix[i][j] != -1)
			{
				(*antpit)->matrix_dup[i][j] = (*antpit)->matrix[i][j];
				j++;
			}
		j = 0;
		i++;
	}
}
void			map_manager(t_map **map, t_path **antpit)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((*map)->cleanfile[i] != NULL)
	{
		if ((*map)->nb_ants == 0)
			check_ants(map, i, 0);
		i++;
	}
	i = (*map)->antindex + 1;
	while ((*map)->error != 1 && (*map)->cleanfile[i] != NULL)
	{
		if ((isroom(map, i, antpit)) == 0 && (istube(map, i, antpit)) == 0)
		{
			if (iscommand(map, i, antpit) <= 0)
				(*map)->error = 1;
		}
		i++;
	}
	if ((*map)->start < 1 || (*map)->end < 1)
		ft_error("there must be at least one start and an end");
	print_matrix(antpit);
	max_paths(antpit);
	ft_printf("YOLO\n");
	matrix_duplicator(antpit);
}
