/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:26:57 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/23 22:07:54 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int	grimly(int fd)
{
	// t_point		exit;
	t_point		entrance;
	t_tile_map	tile_map;
	// t_value_map	dst_map;
	t_sym		sym;

	if (read_tile_map(fd, &tile_map, &entrance, sym))
		return (1);
	// if ((exit = bfs(&tile_map, &dst_map, &entrance, &sym)).x < 0)
	// 	return (1);
	// return (render_path(&tile_map, &dst_map, &exit, sym));
	free_tile_map(&tile_map);
	return (0);
}
