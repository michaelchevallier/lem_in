/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removejunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 11:20:29 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/29 17:17:24 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				removejunk_aux(int i, t_map **map)
{
	if ((*map)->file[i][0] == '#')
	{
		while ((*map)->file[i] && ((*map)->file[i][0] == '#') &&
			(ft_strcmp((*map)->file[i], "##start") != 0 &&
				ft_strcmp((*map)->file[i], "##end") != 0))
			i++;
	}
	return (i);
}

void			remove_junk(t_map **map, int i)
{
	int			j;

	j = 0;
	(*map)->cleanfile = (char **)ft_memalloc(sizeof(char *) * i + 10);
	if (!(*map)->cleanfile || !(*map) || !(*map)->file)
		ft_error("");
	(*map)->cleanfile[i] = NULL;
	i = 0;
	while ((*map)->file[i] != NULL)
	{
		i = removejunk_aux(i, map);
		if ((*map)->file[i])
			(*map)->cleanfile[j] = ft_strdup((*map)->file[i]);
		else
			(*map)->cleanfile[j] = NULL;
		j++;
		i++;
	}
	(*map)->cleanfile[i] = NULL;
	if ((*map)->cleanfile[0] == NULL)
		ft_error("no data inputed");
}
