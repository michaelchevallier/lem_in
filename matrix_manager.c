/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:59:47 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/31 17:53:47 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			mini_id_initialiser(t_map **map, t_path **antpit)
{
	(*antpit)->matrix[(*map)->id1][(*map)->id2] = 1;
	(*antpit)->matrix[(*map)->id2][(*map)->id1] = 1;
}

void			mini_found_manager(t_map **map, t_room **tmp, int found)
{
	if (found == 1)
		((*map)->id1 = (*tmp)->id);
	else
		((*map)->id2 = (*tmp)->id);
}

void			matrix_manager(t_map **map, int i, t_path **antpit)
{
	t_room		*tmp;
	int			found;
	static int	trigger = 0;

	found = 0;
	trigger++;
	tmp = (*antpit)->start;
	(trigger == 1 ? matrix_initialiser(map, antpit) : 0);
	while (tmp)
	{
		if (ft_strcmp((*map)->tab[0], tmp->name) == 0 ||
				ft_strcmp((*map)->tab[1], tmp->name) == 0)
		{
			found++;
			mini_found_manager(map, &tmp, found);
		}
		tmp = tmp->next;
	}
	if (found == 2)
	{
		if ((*map)->id1 > (*antpit)->totalrooms - 1 ||
				(*map)->id2 > (*antpit)->totalrooms - 1)
			ft_error("more room than size of matrix");
		mini_id_initialiser(map, antpit);
	}
}
