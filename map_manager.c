/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:55:44 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/02 19:50:15 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_ants(t_map **map, int i, int j)
{
	int		len;

	len = ft_strlen((*map)->cleanfile[i]);
	if (len == 0)
		ft_error("no ants");
	if ((*map)->cleanfile[i][j] != '#' &&
			(ft_isdigit((*map)->cleanfile[i][j] == 0) &&
				(*map)->cleanfile[i][j] != '+'))
		ft_error("first argument must be the number of ants");
	else if ((*map)->cleanfile[i][j] == '#' && len > 2)
	{
		if ((*map)->cleanfile[i][j + 1] == '#')
			if (ft_strcmp(&(*map)->cleanfile[i][j + 2], "start") == 0 ||
					ft_strcmp(&(*map)->cleanfile[i][j + 2], "end") == 0)
				ft_error("ants can't be start or end");
	}
	else
	{
		(*map)->nb_ants = ft_intmaxatoi((*map)->cleanfile[i]);
		(*map)->antindex = i;
		if ((*map)->nb_ants <= 0 || only_digit((*map)->cleanfile[i]) == 0)
			ft_error("nb ants must be a positive value");
		if ((*map)->nb_ants > 2147483647)
			ft_error("nb must not be more than an integer (2147483647)");
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

void			error_manager(t_map **map, t_path **antpit)
{
	if ((*map)->start < 1 || (*map)->end < 1)
		ft_error("there must be at least one start and an end");
	if ((*antpit)->nb_tubes < 1)
		ft_error("there must be at least one valid tube");
}

void			map_manager(t_map **map, t_path **antpit)
{
	int			i;

	i = 0;
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
	error_manager(map, antpit);
	max_paths(antpit);
	matrix_duplicator(antpit);
}
