/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:52:47 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/03 13:09:00 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	paths_len(t_path **antpit)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	(*antpit)->paths_l = (int *)ft_memalloc(sizeof(int) * (*antpit)->nb_paths);
	while (i <= (*antpit)->nb_paths)
	{
		while ((*antpit)->paths[i][j] != 1)
			j++;
		(*antpit)->paths_l[i] = j;
		j = 0;
		i++;
	}
}

void	start_finder(t_path **antpit, t_map **map)
{
	(*map)->m_start = (*antpit)->end;
	while ((*map)->m_start->isstart != 1)
		(*map)->m_start = (*map)->m_start->prev;
}

void	end_finder(t_path **antpit, t_map **map)
{
	(*map)->m_end = (*antpit)->end;
	while ((*map)->m_end->isend != 1)
		(*map)->m_end = (*map)->m_end->prev;
}

int		ant_sender(t_path **antpit, t_ants **ants, int i, t_room **tmp)
{
	if (((*ants)->total_ants - ((*ants)->total_ants /
		(*antpit)->paths_l[i])) >= (*antpit)->paths_l[i] - 1 ||
		(i == 0 && (*tmp)->ants == NULL))
	{
		(*tmp)->ants = (*ants)->start;
		(*ants)->start = (*ants)->start->next;
		if ((*tmp)->ants != NULL)
			ft_printf("\033[32mL%d-%s \033[0m",
					(*tmp)->ants->a_id, (*tmp)->name);
		(*ants)->total_ants--;
	}
	return (1);
}

void	solve(t_ants **ants, t_map **map, t_path **antpit)
{
	int			i;

	i = 1;
	ants_maker(ants, map);
	paths_len(antpit);
	start_finder(antpit, map);
	end_finder(antpit, map);
	(*map)->m_start->nb_ants = (*map)->nb_ants;
	(*map)->m_start->ants = (*ants);
	if ((*antpit)->nb_paths == 1 && (*antpit)->paths_l[0] == 1)
	{
		while (i <= (*map)->nb_ants)
		{
			ft_printf("\033[32mL%d-1 \033[0m", i);
			i++;
		}
		ft_putchar('\n');
	}
	else
	{
		while ((*map)->m_end->nb_ants < (*map)->nb_ants)
			ant_mover(antpit, map, ants);
	}
}
