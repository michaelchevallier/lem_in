/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_initialiser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:49:14 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/26 14:58:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_matrix(t_path **antpit)
{
	int k = 0;
	int l = 0;
		ft_printf ("   ");
	while (l < (*antpit)->totalrooms)
	{
		ft_printf ("\033[36m%d \033[0m", l);
		l++;
	}
	ft_printf("\n");
	l = 0;
	if (!(*antpit)->matrix)
		ft_error("matrix couldnt be created");
	while ((*antpit)->matrix[k])
	{
		ft_printf("\033[36m%d  \033[0m", k);
		while ((*antpit)->matrix[k][l] != -1)
		{
			ft_printf("%d ", (*antpit)->matrix[k][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		k++;
	}
}
void		matrix_dup_intialiser(t_map **map, t_path **antpit)
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
		matrix_dup_intialiser(map, antpit);
}
