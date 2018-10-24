/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:26:57 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 15:01:04 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"
#include <stdlib.h>
#include <printf.h>

void	render_value_map(t_value_map *vm)
{
	for (int y = 0; y < vm->size.y; y++)
	{
		for (int x = 0; x < vm->size.x; x++)
			printf(" %2d ", vm->value[y][x]);
		printf("\n");
	}
}

int	grimly(int fd)
{
	t_point		exit;
	t_point		*entrance;
	t_tile_map	tile_map;
	t_value_map	dst_map;
	t_sym		sym;

	MCK(entrance = (t_point*)malloc(sizeof(t_point)), 1);
	if (read_tile_map(fd, &tile_map, entrance, sym))
		return (1);
	if ((exit = bfs(&tile_map, &dst_map, entrance, sym)).x < 0)
		return (1);
	render_path(&tile_map, &dst_map, &exit, sym);
	tile_map_free(&tile_map);
	value_map_free(&dst_map);
	return (0);
}
