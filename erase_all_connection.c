/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_all_connection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:33:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/30 14:33:42 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	erase_all_connection(t_path **antpit, t_index **i)
{
	int		m;

	m = 0;
	while (m < (*antpit)->totalrooms)
	{
		(*antpit)->matrix[m][(*i)->i] = 0;
		m++;
	}
	matrix_duplicator(antpit);
	matrix_recopier(antpit);
}
