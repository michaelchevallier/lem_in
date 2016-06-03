/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_finder_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:58:37 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/01 13:38:28 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			destroy_behind(t_path **antpit, t_index **i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while ((*antpit)->allpaths[(*i)->k][j + 1] != 0 &&
			j < (*antpit)->totalrooms - 1)
	{
		if ((*antpit)->allpaths[(*i)->k][j] != 0)
		{
			while (k < (*antpit)->totalrooms)
			{
				((*antpit)->matrix[(*antpit)->allpaths[(*i)->k][j]][k]) = 0;
				(*antpit)->matrix[(*antpit)->allpaths[(*i)->k][j + 1]][k] = 0;
				k++;
			}
		}
		k = 0;
		j++;
	}
}

void			erase_path(t_path **antpit, t_index **i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while ((*antpit)->allpaths[(*i)->k][j + 1] != 0 &&
			j < (*antpit)->totalrooms - 1)
	{
		if ((*antpit)->allpaths[(*i)->k][j] != 0)
		{
			while (k < (*antpit)->totalrooms)
			{
				((*antpit)->matrix[(*antpit)->allpaths[(*i)->k][j]][k]) = 0;
				(*antpit)->matrix[(*antpit)->allpaths[(*i)->k][j + 1]][k] = 0;
				k++;
			}
		}
		k = 0;
		j++;
	}
	matrix_duplicator(antpit);
}

void			matrix_recopier(t_path **antpit)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((*antpit)->matrix_dup[i] != NULL)
	{
		while ((*antpit)->matrix_dup[i][j] != -1)
		{
			(*antpit)->matrix[i][j] = (*antpit)->matrix_dup[i][j];
			j++;
		}
		j = 0;
		i++;
	}
}

void			matrix_partial_recopier(t_path **antpit, t_index **i)
{
	int			j;
	int			l;

	j = 1;
	l = 0;
	while ((*antpit)->allpaths[(*i)->k][j] != -1 &&
			(*antpit)->allpaths[(*i)->k][j + 1] != 0)
	{
		(*antpit)->matrix[l][(*antpit)->allpaths[(*i)->k][j]] = 1;
		l = (*antpit)->allpaths[(*i)->k][j];
		j++;
	}
}
