/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:47:36 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/20 16:19:55 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	map_initializer(t_map **map)
{
	*map = (t_map *)ft_memalloc(sizeof(t_map));
	if (*map)
	{
		(*map)->file = (char **)ft_memalloc(sizeof(char *) * 1024);
		(*map)->map = (int **) ft_memalloc(sizeof(int *) * 1024);
		(*map)->line = NULL;
		(*map)->start = 0;
		(*map)->end = 0;
		(*map)->boolstart = 0;
		(*map)->boolend = 0;
		(*map)->nb_ants = 0;
		(*map)->c_index = 2;
		(*map)->error = 0;
		(*map)->antindex = 0;
		(*map)->tube = 0;
	}
}

int		main(int argc, char **argv)
{
	t_map		*map;
	t_room		*tmp;
	int			i;
	int			k = 0;
	t_path		*antpit;

	i = 0;
	map_initializer(&map);
	if (argc < 1)
		ft_error("not enough arguments");
	while (get_next_line(0, &map->line))
	{
		map->file[i] = ft_strdup(map->line);
		i++;
		if (i % 1024 == 0)
			map->file = ft_realloc(map->file);
	}
	map->tab = (char **)ft_memalloc(sizeof(char *) * i);
	path_initialiser(&antpit, i);
	map->file[i] = NULL;
	remove_junk(&map, i);
	map_manager(&map, &antpit);
	tmp = antpit->start;
	while (tmp)
	{
		ft_printf("\nname[%d] : %s\n",k, (tmp->name));
		ft_printf("coordxy:%d %d  ", tmp->coordx, tmp->coordy);
		ft_printf("id : %d\n", tmp->id);
		k++;
		tmp = tmp->next;
	}
	ft_printf("\nants: %d\n", map->nb_ants);
	k = 0;
	int l = 0;
		ft_printf ("   ");
	while (l < i)
	{
		ft_printf ("\033[36m%d ", l);
		l++;
	}
	ft_printf("\n");
	l = 0;
	while (antpit->matrix[k])
	{
		ft_printf("\033[36m%d  \033[0m", k);
		while (antpit->matrix[k][l] != -1)
		{
		ft_printf("%d ", antpit->matrix[k][l]);
		l++;
		}
		ft_printf("\n");
		l = 0;
		k++;
	}
	ft_printf("totalrooms : %d\n", antpit->totalrooms);
	return (0);
}
