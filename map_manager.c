/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:55:44 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/20 14:21:20 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_ants(t_map **map, int i, int j)
{
	int		len;

	len = ft_strlen((*map)->cleanfile[i]);
	if (len == 0)
		ft_error("nb ants invalid 1");
	if ((*map)->cleanfile[i][j] != '#' &&
			(ft_isdigit((*map)->cleanfile[i][j] == 0) &&
				(*map)->cleanfile[i][j] != '+'))
		ft_error("nb ants invalid 2");
	else if ((*map)->cleanfile[i][j] == '#' && len > 2)
	{
		if ((*map)->cleanfile[i][j + 1] == '#')
			if (ft_strcmp(&(*map)->cleanfile[i][j + 2], "start") == 0 ||
					ft_strcmp(&(*map)->cleanfile[i][j + 2], "end") == 0)
				ft_error("nb ants invalid 3");
	}
	else
	{
		(*map)->nb_ants = ft_atoi((*map)->cleanfile[i]);
		(*map)->antindex = i;
		if ((*map)->nb_ants <= 0 || only_digit((*map)->cleanfile[i]) == 0)
				ft_error("nb ants invalid 4");
	}
}

void			map_manager(t_map **map, t_path **antpit)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((*map)->cleanfile[i] != NULL)
	{
		if ((*map)->nb_ants == 0)
			check_ants(map, i, 0);
		i++;
	}
	i = (*map)->antindex + 1;
	while ((*map)->error != 1 && (*map)->cleanfile[i] != NULL)
	{
		ft_printf("\n\n[%d]%s\n", i,(*map)->cleanfile[i]);
		if ((j = isroom(map, i, antpit)) == 0 && (j = istube(map, i, antpit)) == 0)
		{
			if (iscommand(map, i, antpit) > 0)
			{
				i++;
			}
			else
			{
				(*map)->error = 1;
			}
		}
		i++;
	}
}
