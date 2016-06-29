/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:11:44 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/03 13:20:54 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			paths_initialiser(t_path **antpit)
{
	int			i;

	i = 0;
	(*antpit)->maxpaths_tmp = (*antpit)->maxpaths;
	(*antpit)->paths = (int **)ft_memalloc(sizeof(int *) *
			((*antpit)->maxpaths) + 1);
	(*antpit)->allpaths = (int **)ft_memalloc(sizeof(int *) *
			((*antpit)->totalrooms));
	while (i <= (*antpit)->maxpaths)
	{
		(*antpit)->paths[i] = (int *)ft_memalloc(sizeof(int) *
			((*antpit)->totalrooms));
		i++;
	}
	(*antpit)->paths[i] = NULL;
	i = 0;
	while (i <= (*antpit)->totalrooms)
	{
		(*antpit)->allpaths[i] = (int *)ft_memalloc(sizeof(int) *
			((*antpit)->totalrooms));
		i++;
	}
}

void			max_paths(t_path **antpit)
{
	int			i;
	int			mx1;
	int			mx2;

	i = 0;
	mx1 = 0;
	mx2 = 0;
	while ((*antpit)->matrix[0][i] != -1)
	{
		if ((*antpit)->matrix[0][i] == 1)
			mx1++;
		i++;
	}
	i = 0;
	while ((*antpit)->matrix[1][i] != -1)
	{
		if ((*antpit)->matrix[1][i] == 1)
			mx2++;
		i++;
	}
	if (mx1 < mx2)
		((*antpit)->maxpaths = mx1);
	else
		((*antpit)->maxpaths = mx2);
	paths_initialiser(antpit);
}

int				path_copy(t_path **antpit, int j)
{
	int		i;

	i = 0;
	while ((*antpit)->allpaths[(*antpit)->path_found - 1][i] != 1 &&
			i < (*antpit)->totalrooms - 1)
	{
		(*antpit)->paths[j][i] =
			(*antpit)->allpaths[(*antpit)->path_found - 1][i];
		i++;
	}
	(*antpit)->paths[j][i] = 1;
	if (i == 1)
	{
		(*antpit)->maxpaths_tmp = 1;
		(*antpit)->nb_paths = 1;
		return (1);
	}
	else
		return (0);
}

void			paths_finder(t_map **map, t_path **antpit)
{
	int			depth;
	int			path_result;
	int			j;
	t_index		*i;

	depth = 1;
	path_result = 0;
	j = 0;
	index_initialiser(&i);
	while (depth <= (*antpit)->totalrooms && (*antpit)->maxpaths_tmp != 0)
	{
		i->m = 0;
		path_result = find_paths(map, antpit, &i, depth);
		depth++;
		index_initialiser(&i);
		if (path_result > 0)
		{
			j++;
			(*antpit)->maxpaths_tmp--;
		}
		matrix_recopier(antpit);
		if ((*antpit)->path_found > 0 && depth > (*map)->nb_ants)
			depth = (*antpit)->totalrooms + 1;
	}
	(j == 0 && (*antpit)->path_found == 0) ? (ft_error("No path found")) : 0;
}
