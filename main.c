/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:47:36 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/02 20:49:50 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	map_initializer(t_map **map)
{
	*map = (t_map *)ft_memalloc(sizeof(t_map));
	if (*map)
	{
		(*map)->file = (char **)ft_memalloc(sizeof(char *) * 1024);
		(*map)->map = (int **)ft_memalloc(sizeof(int *) * 1024);
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
		(*map)->id1 = -1;
		(*map)->id2 = -1;
	}
}

void	print_file(t_map **map)
{
	int			i;

	i = 0;
	while ((*map)->file[i] != NULL)
	{
		ft_putstr((*map)->file[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_map		*map;
	t_room		*tmp;
	t_ants		*ants;
	int			i;
	t_path		*antpit;

	i = 0;
	map_initializer(&map);
	while (get_next_line(0, &map->line))
	{
		map->file[i] = ft_strdup(map->line);
		i++;
		if (i % 1024 == 0)
			map->file = ft_realloc(map->file);
	}
	map->file[i] = NULL;
	map->tab = (char **)ft_memalloc(sizeof(char *) * i);
	print_file(&map);
	remove_junk(&map, i);
	path_initialiser(&antpit);
	map_manager(&map, &antpit);
	paths_finder(&map, &antpit);
	solve(&ants, &map, &antpit);
	return (0);
}
