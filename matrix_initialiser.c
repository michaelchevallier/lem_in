/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_initialiser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:49:14 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/02 19:01:27 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		matrix_dup_initialiser(t_map **map, t_path **antpit)
{
	int		i;
	int		j;

	i = (*antpit)->totalrooms;
	j = 0;
	(*antpit)->matrix_dup = (int **)ft_memalloc(sizeof(int *) * i + 1);
	if ((*antpit)->matrix)
	{
		(*antpit)->matrix_dup[i] = NULL;
		while (j < i)
		{
			(*antpit)->matrix_dup[j] = (int *)ft_memalloc(sizeof(int) *
					i + 1);
			(*antpit)->matrix_dup[j][i] = -1;
			j++;
		}
	}
	else
		ft_error("matrix couldnt be created");
}

void		matrix_initialiser(t_map **map, t_path **antpit)
{
	int		i;
	int		j;

	i = (*antpit)->totalrooms;
	j = 0;
	(*antpit)->matrix = (int **)ft_memalloc(sizeof(int *) * i + 1);
	if ((*antpit)->matrix)
	{
		(*antpit)->matrix[i] = NULL;
		while (j < i)
		{
			(*antpit)->matrix[j] = (int *)ft_memalloc(sizeof(int) * i + 1);
			(*antpit)->matrix[j][i] = -1;
			j++;
		}
	}
	else
		ft_error("matrix couldnt be created");
	matrix_dup_initialiser(map, antpit);
}
