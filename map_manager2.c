/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:22:30 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/01 18:58:16 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_room_validity(t_map **map, t_path **antpit)
{
	t_room		*tmp;

	tmp = (*antpit)->start;
	if ((*map)->tube != 0)
		return (0);
	else
	{
		while (tmp)
		{
			if (ft_strcmp((*map)->tab[0], tmp->name) == 0)
				ft_error("same name for two rooms");
			if (ft_atoi((*map)->tab[1]) == tmp->coordx &&
					ft_atoi((*map)->tab[2]) == tmp->coordy)
				ft_error("same coordinates for two rooms");
			tmp = tmp->next;
		}
	}
	return (1);
}

int			check_tube_validity(t_map **map, t_path **antpit)
{
	t_room		*tmp;
	int			check;

	check = 0;
	tmp = (*antpit)->start;
	if (ft_strcmp((*map)->tab[0], (*map)->tab[1]) == 0)
		return (0);
	while (tmp)
	{
		if (ft_strcmp((*map)->tab[0], tmp->name) == 0)
			check++;
		if (ft_strcmp((*map)->tab[1], tmp->name) == 0)
			check++;
		tmp = tmp->next;
	}
	if (check != 2)
		return (0);
	return (1);
}

int			isroom(t_map **map, int i, t_path **antpit)
{
	int			j;
	int			countspaces;

	j = 0;
	countspaces = 0;
	if ((*map)->cleanfile[i][j] == '#' || (*map)->cleanfile[i][j] == 'L' ||
		(ft_strchr((*map)->cleanfile[i], '-') != NULL))
		return (0);
	while ((*map)->cleanfile[i][j] != '\0')
	{
		if ((*map)->cleanfile[i][j] == ' ')
			countspaces++;
		j++;
	}
	if (countspaces != 2)
		return (0);
	(*map)->tab = ft_strsplit((*map)->cleanfile[i], ' ');
	if (!(*map)->tab[2] || !(*map)->tab[1])
		return (0);
	if (only_digit((*map)->tab[1]) == 0 || only_digit((*map)->tab[2]) == 0)
		return (0);
	if (check_room_validity(map, antpit) == 0)
		return (0);
	list_maker(map, antpit);
	return (i);
}

int			istube(t_map **map, int i, t_path **antpit)
{
	int			j;
	int			hyphen;

	j = 0;
	hyphen = 0;
	while ((*map)->cleanfile[i][j] != '\0')
	{
		if ((*map)->cleanfile[i][j] == '-')
			hyphen++;
		j++;
	}
	if ((*map)->cleanfile[i][j] == '#' || hyphen != 1 ||
			ft_strchr((*map)->cleanfile[i], ' ') != NULL)
		return (0);
	(*map)->tab = ft_strsplit((*map)->cleanfile[i], '-');
	if (check_tube_validity(map, antpit) == 0)
		return (0);
	matrix_manager(map, i, antpit);
	(*antpit)->nb_tubes++;
	return (1);
}

int			iscommand(t_map **map, int i, t_path **antpit)
{
	if (ft_strcmp((*map)->cleanfile[i], "##start") == 0)
	{
		if ((*map)->boolend == 1 || (*map)->start == 1)
			(*map)->error = 1;
		(*map)->start++;
		(*map)->boolstart = 1;
		return (1);
	}
	else if (ft_strcmp((*map)->cleanfile[i], "##end") == 0)
	{
		if ((*map)->boolstart == 1 || (*map)->end == 1)
			(*map)->error = 1;
		(*map)->end++;
		(*map)->boolend = 1;
		return (1);
	}
	else
		return (0);
}
