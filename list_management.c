/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 14:42:26 by mchevall          #+#    #+#             */
/*   Updated: 2016/06/02 14:29:06 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			path_initialiser(t_path **list)
{
	*list = (t_path *)ft_memalloc(sizeof(t_path));
	if (*list)
	{
		(*list)->start = NULL;
		(*list)->end = NULL;
		(*list)->length = 0;
		(*list)->totalrooms = 0;
		(*list)->maxpaths = 0;
		(*list)->maxpaths_tmp = 0;
		(*list)->paths_l = NULL;
		(*list)->nb_paths = 0;
		(*list)->path_found = 0;
		(*list)->nb_tubes = 0;
	}
}

void			room_initialiser(t_room **room, t_map **map)
{
	(*room)->ants = NULL;
	(*room)->next = NULL;
	(*room)->prev = NULL;
	(*room)->name = ft_strdup((*map)->tab[0]);
	(*room)->coordx = ft_atoi((*map)->tab[1]);
	(*room)->coordy = ft_atoi((*map)->tab[2]);
	(*room)->isstart = (*map)->boolstart;
	(*room)->isend = (*map)->boolend;
	(*room)->nb_ants = 0;
	(*room)->c_path = 0;
}

void			room_maker(t_room **room, t_map **map)
{
	static int		id = 2;

	if ((*map)->boolstart == 1 || (*map)->boolend == 1)
		id--;
	*room = (t_room *)ft_memalloc(sizeof(t_room));
	if (*room)
	{
		room_initialiser(room, map);
		if ((*map)->boolstart == 1)
		{
			(*room)->id = 0;
			(*map)->boolstart = 0;
		}
		else if ((*map)->boolend == 1)
		{
			(*room)->id = 1;
			(*map)->boolend = 0;
		}
		else
			(*room)->id = id;
	}
	id++;
}

void			room_add(t_path **list, t_room *new_room)
{
	int		i;

	i = 0;
	if (!(*list)->end)
		(*list)->end = new_room;
	else
	{
		(*list)->start->prev = new_room;
		new_room->prev = NULL;
		new_room->next = (*list)->start;
	}
	(*list)->start = new_room;
	(*list)->totalrooms++;
}

void			list_maker(t_map **map, t_path **start)
{
	t_room		*room;

	room_maker(&room, map);
	room_add(start, room);
}
