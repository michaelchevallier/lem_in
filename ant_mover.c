/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_mover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 18:56:40 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/03 16:51:51 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	tmp_init(t_path **antpit, int tmplen, int i, t_room **tmp)
{
	*tmp = (*antpit)->end;
	while ((*tmp)->id != (*antpit)->paths[i][tmplen])
		*tmp = (*tmp)->prev;
}

void	tmp2_init(t_path **antpit, int tmplen, int i, t_room **tmp2)
{
	*tmp2 = (*antpit)->end;
	while ((*tmp2)->id != (*antpit)->paths[i][tmplen - 1])
		*tmp2 = (*tmp2)->prev;
}

void	ants_move(t_room **tmp, t_map **map, t_room **tmp2)
{
	if ((*map)->m_end->ants != NULL)
	{
		(*map)->m_end->nb_ants++;
		(*map)->m_end->ants = NULL;
	}
	(*tmp)->ants = (*tmp2)->ants;
	(*tmp2)->ants = NULL;
	if ((*tmp)->ants != NULL)
	{
		ft_printf("\033[32mL%d-%s \033[0m", (*tmp)->ants->a_id, (*tmp)->name);
	}
}

void	ant_mover(t_path **antpit, t_map **map, t_ants **ants)
{
	int			i;
	int			tmplen;
	t_room		*tmp;
	t_room		*tmp2;

	i = 0;
	while (i < (*antpit)->nb_paths &&
		((*map)->m_end->nb_ants < (*map)->m_start->nb_ants))
	{
		tmplen = (*antpit)->paths_l[i];
		while (tmplen > 0)
		{
			tmp_init(antpit, tmplen, i, &tmp);
			tmp2_init(antpit, tmplen, i, &tmp2);
			if (tmplen == 1 && (*ants)->total_ants > 0)
				ant_sender(antpit, ants, i, &tmp);
			else if ((tmp->isend == 1 || tmp->ants == NULL) && tmplen > 1)
				ants_move(&tmp, map, &tmp2);
			tmplen--;
		}
		i++;
	}
	ft_printf("\n");
}
