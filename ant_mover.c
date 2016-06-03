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

void	ants_move(t_room **tmp, t_room **end, t_room **tmp2)
{
	ft_printf("AA");
	if ((*end)->ants != NULL)
	{
		(*end)->nb_ants++;
		(*end)->ants = NULL;
	}
	(*tmp)->ants = (*tmp2)->ants;
	(*tmp2)->ants = NULL;
	if ((*tmp)->ants != NULL && (*end)->ants != NULL)
	{
		ft_printf("B");
		ft_printf("\033[32mL%d-%s \033[0m", (*tmp)->ants->a_id, (*tmp)->name);
	}
}

void	ant_mover(t_path **antpit, t_room **end, t_room **start, t_ants **ants)
{
	int			i;
	int			tmplen;
	t_room		*tmp;
	t_room		*tmp2;

	i = 0;
	while (i < (*antpit)->nb_paths && ((*end)->nb_ants < (*start)->nb_ants - 1))
	{
		tmplen = (*antpit)->paths_l[i];
		while (tmplen > 0)
		{
			tmp_init(antpit, tmplen, i, &tmp);
			tmp2_init(antpit, tmplen, i, &tmp2);
			if (tmplen == 1 && (*ants)->total_ants > 0)
			{
				ant_sender(antpit, ants, i, &tmp);// == 0)
					//(*end)->ants = NULL;
			}
			else if (tmp->isend == 1 || tmp->ants == NULL)
			{
	ft_printf("C");
				ants_move(&tmp, end, &tmp2);
			}
			tmplen--;
		}
		i++;
	}
	ft_printf("\n");
}
