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

void	start_finder(t_path **antpit, t_room **start)
{
	*start = (*antpit)->end;
	while ((*start)->isstart != 1)
		*start = (*start)->prev;
}

void	end_finder(t_path **antpit, t_room **end)
{
	*end = (*antpit)->end;
	while ((*end)->isend != 1)
		*end = (*end)->prev;
}

int		ant_sender(t_path **antpit, t_ants **ants, int i, t_room **tmp)
{
	t_room		*start;
	t_room		*end;

	ft_printf("");
	start_finder(antpit, &start);
	end_finder(antpit, &start);
	if (((*ants)->total_ants - ((*ants)->total_ants /
		(*antpit)->paths_l[i])) >= (*antpit)->paths_l[i] || i == 0)
	{
		(*tmp)->ants = (*ants)->start;
		(*ants)->start = (*ants)->start->next;
		if ((*tmp)->ants != NULL)
			ft_printf("\033[32mL%d-%s \033[0m",
					(*tmp)->ants->a_id, (*tmp)->name);
		(*ants)->total_ants--;
	}
	if ((*ants)->total_ants == 0)
	{
		(*antpit)->start->ants = NULL;
		return (0);
	}
	return (1);
}

void	solve(t_ants **ants, t_map **map, t_path **antpit)
{
	t_room		*start;
	t_room		*end;
	int			i;

	i = 1;
	ants_maker(ants, map);
	paths_len(antpit);
	start_finder(antpit, &start);
	end_finder(antpit, &end);
	start->nb_ants = (*map)->nb_ants;
	start->ants = (*ants);
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
		while (end->nb_ants < (*map)->nb_ants - 1)
			ant_mover(antpit, &end, &start, ants);
	}
}
