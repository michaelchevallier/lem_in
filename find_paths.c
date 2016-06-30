/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:02:58 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/30 14:33:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		path_found(t_path **antpit, t_index **i, int j)
{
	matrix_duplicator(antpit);
	(*antpit)->allpaths[(*i)->k][(*i)->l + 1] = 1;
	(*antpit)->path_found = (*i)->k + 1;
	(*antpit)->nb_paths++;
	path_copy(antpit, j);
	j++;
	erase_path(antpit, i);
	return (j);
}

void	room_found(t_path **antpit, t_index **i, t_map **map, int depth)
{
	(*antpit)->allpaths[(*i)->k][(*i)->l + 1] = (*i)->j;
	(*i)->l++;
	(*antpit)->matrix[(*i)->i][(*i)->j] = 0;
	(*antpit)->matrix[(*i)->j][(*i)->i] = 0;
	(*i)->i = (*i)->j;
	(*i)->j = 0;
	find_paths(map, antpit, i, depth);
	(*i)->k++;
}

void	path_not_found(t_path **antpit, t_index **i, t_map **map, int depth)
{
	matrix_recopier(antpit);
	(*antpit)->matrix[(*i)->i][(*i)->j] = 0;
	erase_all_connection(antpit, i);
	find_paths(map, antpit, i, depth);
}

int		depth_change(t_path **antpit, t_index **i, t_map **map, int depth)
{
	(*i)->i = 0;
	(*i)->m = 0;
	(*i)->l = 0;
	(*i)->k++;
	if (find_paths(map, antpit, i, depth) != 0)
	{
		(*antpit)->matrix[(*i)->i][(*i)->j] = 0;
		(*antpit)->path_found = (*i)->k + 1;
		return (1);
	}
	else
		return (0);
}

int		find_paths(t_map **map, t_path **antpit, t_index **i, int depth)
{
	static int	j = 0;

	if ((*i)->m >= depth)
		return (depth_change(antpit, i, map, depth));
	(*i)->m++;
	while ((*i)->j++ < (*antpit)->totalrooms)
	{
		if ((*antpit)->matrix[(*i)->i][1] == 1)
		{
			j = path_found(antpit, i, j);
			return (1);
		}
		else if ((*antpit)->matrix[(*i)->i][(*i)->j] == 1)
			room_found(antpit, i, map, depth);
		else if ((*i)->j == (*antpit)->totalrooms - 1)
		{
			if ((*i)->i == 0)
				return (0);
			path_not_found(antpit, i, map, depth);
		}
	}
	(*i)->i = 0;
	(*i)->j = 0;
	(*i)->l = 0;
	return ((*antpit)->path_found);
}
