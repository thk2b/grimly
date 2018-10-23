/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:57:08 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/23 16:43:40 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_tile_map
{
	t_point	size;
	char	**tile;
}				t_tile_map;

typedef	struct	s_value_map
{
	t_point	size;
	int		**value;
}				t_value_map;

typedef char	t_sym[5];

int				grimly(int fd);
t_point			read_tile_map(int fd, t_tile_map* tile_map, t_point *entrance, t_sym *sym);
t_point			bfs(t_tile_map *tile_map, t_value_map *dst_map,
	t_point *entrance, t_sym *sym);
int				render_path(t_tile_map *tile_map, t_value_map *val_map,
	t_point *exit, t_sym *sym);

#endif
