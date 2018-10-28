/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:57:08 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 11:27:27 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# define MAX_MAP 1000000000
# include "point.h"

typedef struct	s_tile_map
{
	t_point	size;
	char	**tile;
}				t_tile_map;

typedef	struct	s_parent_map
{
	t_point	size;
	t_point	**value;
}				t_parent_map;

enum			e_syms
{
	SYM_FULL, SYM_EMPTY, SYM_PATH, SYM_ENTRANCE, SYM_EXIT
};
typedef char	t_sym[5];

int				grimly(int fd);
void			tile_map_free(t_tile_map *tm);
int				read_tile_map(int fd, t_tile_map *tile_map,
	t_point *entrance, t_sym sym);
int				print_tile_map(t_tile_map *tm, int steps, t_sym sym);
int				value_map_new(t_parent_map *vm, t_point *size);
void			value_map_free(t_parent_map *vm);
t_point			bfs(t_tile_map *tile_map, t_parent_map *parent_map,
	t_point *entrance, t_sym sym);
int				render_path(t_tile_map *tile_map, t_parent_map *parent_map,
	t_point *exit, t_sym sym);

#endif
