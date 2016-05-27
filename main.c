/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:47:36 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/27 15:07:07 by mchevall         ###   ########.fr       */
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
		(*map)->id1 = -1;
		(*map)->id2 = -1;
	}
}

int		main(int argc, char **argv)
{
	t_map		*map;
	t_room		*tmp;
	int			i;
	int			k = 0;
	int			l = 0;
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
	map->tab = (char **)ft_memalloc(sizeof(char *) * i);
	path_initialiser(&antpit);
	map->file[i] = NULL;
	ft_printf("#################\n");
	remove_junk(&map, i);
	ft_printf("AAAAAAAAAAAAAAAAAAAAAAAA\n");
	map_manager(&map, &antpit);
	solve(&map, &antpit);
	tmp = antpit->start;
	while (tmp)
	{
		ft_printf("\nname[%d] : %s\n",k, (tmp->name));
		ft_printf("coordxy:%d %d  ", tmp->coordx, tmp->coordy);
		ft_printf("id : %d  is start: %d isend : %d\n", tmp->id, tmp->isstart, tmp->isend);
		k++;
		tmp = tmp->next;
	}
		while (l < antpit->totalrooms)
		{
			ft_printf("path[0][%d] : %d\n", l,antpit->paths[0][l]);
			l++;
		}
		l = 0;
		ft_printf("\n");
		while (l < antpit->totalrooms)
		{
			ft_printf("path[1][%d] : %d\n", l,antpit->paths[1][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		while (l < antpit->totalrooms)
		{
			ft_printf("path[2][%d] : %d\n", l,antpit->paths[2][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		while (l < antpit->totalrooms)
		{
			ft_printf("allpath[0][%d] : %d\n", l,antpit->allpaths[0][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		while (l < antpit->totalrooms)
		{
			ft_printf("allpath[1][%d] : %d\n", l,antpit->allpaths[1][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		/*while (l < antpit->totalrooms)
		{
			ft_printf("path[5][%d] : %d\n", l,antpit->allpaths[5][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		while (l < antpit->totalrooms)
		{
			ft_printf("path[6][%d] : %d\n", l,antpit->allpaths[6][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		while (l < antpit->totalrooms)
		{
			ft_printf("path[7][%d] : %d\n", l,antpit->allpaths[7][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		while (l < antpit->totalrooms)
		{
			ft_printf("path[8][%d] : %d\n", l,antpit->allpaths[8][l]);
			l++;
		}
		ft_printf("\n");
		l = 0;
		while (l < antpit->totalrooms)
		{
			f_printf("path[9][%d] : %d\n", l,antpit->allpaths[9][l]);
			l++;
		}*/
	ft_printf("\nants: %d\n", map->nb_ants);
	k = 0;
	print_matrix(&antpit);
	ft_printf("totalrooms : %d\n", antpit->totalrooms);
	ft_printf("map->error %d\n", map->error);
	ft_printf("antpit->maxpaths %d\n", antpit->maxpaths);
	return (0);
}
