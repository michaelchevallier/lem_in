/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:28:23 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/27 16:22:07 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
void			paths_initialiser(t_path **antpit)
{
	int			i;

	i = 0;
	(*antpit)->paths = (int **)ft_memalloc(sizeof(int *) * ((*antpit)->maxpaths) + 1);
	(*antpit)->allpaths = (int **)ft_memalloc(sizeof(int *) *
			((*antpit)->totalrooms));
	(*antpit)->paths[(*antpit)->maxpaths + 1] = NULL;
	while (i <= (*antpit)->maxpaths)
	{
		(*antpit)->paths[i] = (int *)ft_memalloc(sizeof(int) *
				((*antpit)->totalrooms));
				i++;
	}
	i = 0;
	while (i <= (*antpit)->totalrooms)
	{
		(*antpit)->allpaths[i] = (int *)ft_memalloc(sizeof(int) *
				((*antpit)->totalrooms));
				i++;
	}
}

void			max_paths(t_path **antpit)
{
	int			i;
	int			mx1;
	int			mx2;

	i = 0;
	mx1 = 0;
	mx2 = 0;
	while ((*antpit)->matrix[0][i] != -1)
	{
		if ((*antpit)->matrix[0][i] == 1)
			mx1++;
		i++;
	}
	i = 0;
	while ((*antpit)->matrix[1][i] != -1)
	{
		if ((*antpit)->matrix[1][i] == 1)
			mx2++;
		i++;
	}
	(mx1 < mx2 ) ? ((*antpit)->maxpaths = mx1) : ((*antpit)->maxpaths = mx2);
	paths_initialiser(antpit);
}

void			destroy_behind(t_path **antpit, t_index **i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while ((*antpit)->allpaths[(*i)->k][j + 1] != 0 && j < (*antpit)->totalrooms - 1)
	{
		if ((*antpit)->allpaths[(*i)->k][j] != 0)
		{
		while (k < (*antpit)->totalrooms)
		{
			((*antpit)->matrix[(*antpit)->allpaths[(*i)->k][j]]
			[k]) = 0;
			(*antpit)->matrix[(*antpit)->allpaths[(*i)->k]
			[j + 1]][k] = 0;
			k++;
		}
		}
		k = 0;
		j++;
	}
}

void			erase_path(t_path **antpit, t_index **i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	ft_printf("\n\ni: %d j: %d  k: %d l: %d\n", (*i)->i, (*i)->j, (*i)->k, (*i)->l);
	ft_printf("#######################\n############################\n %d\n######################################\n #########################",(*antpit)->matrix[(*antpit)->allpaths[(*i)->k][j]]);
	ft_printf("\n%d\nj:%d k:%d ", (*antpit)->matrix[0][0], j, (*i)->k);
	ft_printf("\n ant : %d\n",(*antpit)->allpaths[(*i)->k][j + 1]);

	ft_printf("\nbefore\n");
	print_matrix(antpit);
	while ((*antpit)->allpaths[(*i)->k][j + 1] != 0 && j < (*antpit)->totalrooms - 1)
	{
		if ((*antpit)->allpaths[(*i)->k][j] != 0)
		{
			while (k < (*antpit)->totalrooms)
			{
				((*antpit)->matrix[(*antpit)->allpaths[(*i)->k][j]][k]) = 0;
				(*antpit)->matrix[(*antpit)->allpaths[(*i)->k][j + 1]][k] = 0;
				k++;
			}
		}
		k = 0;
		j++;
	}
	print_matrix(antpit);
	matrix_duplicator(antpit);
}

int				find_paths(t_map **map, t_path **antpit, t_index **i, int depth)
{
	static int	j = 0;
	(*i)->j = 0;
	if ((*i)->m >= depth)// && depth != 1)
	{
		(*i)->i = 0;
		(*i)->m = 0;
		(*i)->l = 0;
		(*i)->k++;
		if (find_paths(map, antpit, i, depth) != 0)
		{
			(*antpit)->matrix[(*i)->i][(*i)->j] = 0;
			//matrix_duplicator(antpit);
			//ft_printf("1\033[35m ###   SOLUTION FOUND ###\n \033[0m");
			//matrix_recopier(antpit);
			//erase_path(antpit, i);
			(*antpit)->path_found = (*i)->k + 1;
			return (1);
		}
		else
			return (0);
	}
	(*i)->m++;
	ft_printf("\n i: %d j: %d  k: %d l: %d m: %d\n", (*i)->i, (*i)->j, (*i)->k, (*i)->l, (*i)->m);
	while ((*i)->j < (*antpit)->totalrooms)
	{
		if ((*antpit)->matrix[(*i)->i][1] == 1)
		{
			(*antpit)->matrix[(*i)->i][(*i)->j] = 0;
			(*antpit)->matrix[(*i)->j][(*i)->i] = 0;
			matrix_duplicator(antpit);
			ft_printf("2\033[35m ###   SOLUTION FOUND ###\n \033[0m");
			(*antpit)->allpaths[(*i)->k][(*i)->l + 1] = 1;
			ft_printf("\npath[%d][%d] : index: [%d]\n", (*i)->k, (*i)->l + 1,1);
			(*antpit)->path_found = (*i)->k + 1;
			path_copy(antpit, j);
			j++;
			erase_path(antpit, i);
			//matrix_recopier(antpit);
			return (1);
		}
		else if ((*antpit)->matrix[(*i)->i][(*i)->j] == 1)
		{
			ft_printf(" **  tube trouve ** ");
			(*antpit)->allpaths[(*i)->k][(*i)->l + 1] = (*i)->j;
			ft_printf("\npath[%d][%d] : index: [%d]\n", (*i)->k, (*i)->l + 1,(*i)->j);
			(*i)->l++;
				ft_printf("erasing\n");
			//destroy_behind(antpit, i);
			(*antpit)->matrix[(*i)->i][(*i)->j] = 0;
			(*antpit)->matrix[(*i)->j][(*i)->i] = 0;
			//matrix_duplicator(antpit);
			//matrix_recopier(antpit);
			ft_printf("\nchange i : %d -> %d\n", (*i)->i, (*i)->j);
			(*i)->i = (*i)->j;
			find_paths(map, antpit, i, depth);
			(*i)->k++;
		}
		/*else if ((*i)->j == (*antpit)->totalrooms - 1)
		{
			ft_printf ("\n\n %% test %% \n\n");
			matrix_recopier(antpit);
			(*antpit)->matrix[(*i)->i][0] = 0;
			//(*antpit)->matrix[(*i)->j][(*i)->i] = 0;
			matrix_duplicator(antpit);
		}*/
		ft_printf(" **tour de boucle **  ");
		(*i)->j++;
	}
			ft_printf("  sortie de boucle  ");
	(*i)->i = 0;
	(*i)->j = 0;
	(*i)->l = 0;
	ft_printf("\n i: %d j: %d  k: %d l: %d m: %d\n", (*i)->i, (*i)->j, (*i)->k, (*i)->l, (*i)->m);
	return ((*antpit)->path_found);
}

void			matrix_recopier(t_path **antpit)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((*antpit)->matrix_dup[i] != NULL)
	{
		while ((*antpit)->matrix_dup[i][j] != -1)
			{
				(*antpit)->matrix[i][j] = (*antpit)->matrix_dup[i][j];
				j++;
			}
		j = 0;
		i++;
	}
}

void			path_copy(t_path **antpit, int j)
{
	int		i;

	i = 0;
	while ((*antpit)->allpaths[(*antpit)->path_found - 1][i] != 1 && i < (*antpit)->totalrooms - 1)
	{
		(*antpit)->paths[j][i] = (*antpit)->allpaths[(*antpit)->path_found - 1][i];
		i++;
	}
	(*antpit)->paths[j][i] = 1;
}

void			solve(t_map **map, t_path **antpit)
{
	int			depth;
	int			path_result;
	int			j;
	t_index		*i;
	int l =0;

	depth = 1;
	path_result = 0;
	j = 0;
	print_matrix(antpit);
	index_initialiser(&i);
	ft_printf("\n\033[034m##### depth: %d\n\033[0m", depth);
	while (depth != (*antpit)->totalrooms && (*antpit)->maxpaths != 0)
	{
		i->m = 0;
		path_result = find_paths(map, antpit, &i, depth);
		depth++;
		ft_printf("\n\033[034m##### depth: %d\n\033[0m", depth);
		index_initialiser(&i);
		if (path_result > 0)
		{
			j++;
			(*antpit)->maxpaths--;
		}
		matrix_recopier(antpit);
		(*antpit)->path_found = 0;
	}
	(j == 0) ? (ft_error("No path found")) : 0;
	ft_printf("SWAAAAAAAG");
}
