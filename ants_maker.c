/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:47:45 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/01 18:22:27 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_ant(t_ants **list, t_ants *ant, int i)
{
	if (!(*list)->start)
		(*list)->start = ant;
	else
	{
		(*list)->end->next = ant;
		ant->prev = (*list)->start;
		ant->next = NULL;
	}
	(*list)->end = ant;
	(*list)->total_ants++;
}

void			ants_initialiser(t_ants **list, int i)
{
	if (!*list)
		*list = (t_ants *)ft_memalloc(sizeof(t_ants));
	if (*list)
	{
		(*list)->start = NULL;
		(*list)->end = NULL;
		(*list)->next = NULL;
		(*list)->prev = NULL;
		(*list)->a_id = i;
		(*list)->r_id = 0;
		(*list)->total_ants = 0;
	}
}

void			ant_maker(t_ants **ants, int i)
{
	*ants = (t_ants *)ft_memalloc(sizeof(t_ants));
	if (*ants)
		ants_initialiser(ants, i);
}

void			ants_maker(t_ants **list, t_map **map)
{
	int			i;
	t_ants		*ant;

	i = 1;
	ants_initialiser(list, i);
	{
		while (i <= (*map)->nb_ants)
		{
			ant_maker(&ant, i);
			ants_initialiser(&ant, i);
			add_ant(list, ant, i);
			i++;
		}
	}
}
