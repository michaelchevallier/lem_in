/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removejunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:20:29 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/17 11:20:43 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			remove_junk(t_map **map, int i)
{
	int			j;

	j = 0;
	(*map)->cleanfile = (char **)ft_memalloc(sizeof(char *) * i);
	(*map)->cleanfile[i] = NULL;
	i = 0;
	while ((*map)->file[i] != NULL)
	{
		if ((*map)->file[i][0] == '#')
		{
			if (ft_strcmp((*map)->file[i], "##start") != 0 &&
					ft_strcmp((*map)->file[i], "##end") != 0)
				i++;
		}
		(*map)->cleanfile[j] = ft_strdup((*map)->file[i]);
		j++;
		i++;
	}
}
