/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:26:57 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 11:24:07 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"
#include <stdlib.h>

int		grimly(int fd)
{
	t_point			exit;
	t_point			*entrance;
	t_tile_map		tile_map;
	t_parent_map	parent_map;
	t_sym			sym;

	MCK(entrance = (t_point*)malloc(sizeof(t_point)), 1);
	if (read_tile_map(fd, &tile_map, entrance, sym))
		return (1);
	if ((exit = bfs(&tile_map, &parent_map, entrance, sym)).x < 0)
	{
		tile_map_free(&tile_map);
		value_map_free(&parent_map);
		return (1);
	}
	render_path(&tile_map, &parent_map, &exit, sym);
	tile_map_free(&tile_map);
	value_map_free(&parent_map);
	return (0);
}
