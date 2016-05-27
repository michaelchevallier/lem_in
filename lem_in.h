/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:37:14 by mchevall          #+#    #+#             */
/*   Updated: 2016/05/27 15:29:39 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf/ft_printf.h"

typedef struct		s_map
{
	char			*line;
	char			**file;
	char			**cleanfile;
	char			**tab;
	int				start;
	int				boolstart;
	int				end;
	int				boolend;
	int				error;
	int				nb_ants;
	int				c_index;
	int				**map;
	int				antindex;
	int				tube;
	int				id1;
	int				id2;
}					t_map;

typedef struct		s_room
{
	struct s_room	*next;
	struct s_room	*prev;
	char			*name;
	int				coordx;
	int				coordy;
	int				busy;
	int				c_path;
	int				isstart;
	int				isend;
	int				id;
}					t_room;

typedef struct		s_path
{
	t_room			*start;
	t_room			*end;
	int				path_found;
	int				maxpaths;
	int				**allpaths;
	int				**paths;
	int				**matrix;
	int				**matrix_dup;
	int				length;
	int				totalrooms;
}					t_path;

typedef struct		s_index
{
	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
}					t_index;

void				ft_error(char *str);
void				map_manager(t_map **map, t_path **antpit);
void				remove_junk(t_map **map, int i);
char				**ft_realloc(char **tab);
int					isroom(t_map **map, int i, t_path **antpit);
int					istube(t_map **map, int i, t_path **antpit);
int					iscommand(t_map **map, int i, t_path **antpit);
int					only_digit(char *file);
void				path_initialiser(t_path **list);
void				room_maker(t_room **room, t_map **map);
void				room_add(t_path **list, t_room *new_room);
void				list_maker(t_map **map, t_path **start);
void				matrix_initialiser(t_map **map, t_path **antpit);
void				print_matrix(t_path **antpit);
void				solve(t_map **map, t_path **antpit);
int					find_paths(t_map **map, t_path **antpit, t_index **i, int depth);
void				max_paths(t_path **antpit);
void				index_initialiser(t_index **i);
void				matrix_recopier(t_path **antpit);
void				matrix_duplicator(t_path **antpit);
void				path_copy(t_path **antpit, int j);
#endif
