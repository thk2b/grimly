/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:32:03 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 13:24:26 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "point.h"
#include "queue.h"
#include "libft.h"

t_point		bfs(t_tile_map *tile_map, t_value_map *dst_map,
	t_point *entrance, t_sym sym)
{
	t_queue	*q;
	t_point	*cur;
	t_point	*dup;
	t_point	next = {0, 0};
	char	next_tile;

	if (value_map_new(dst_map, &tile_map->size))
		return ((t_point){-1, -1});
	if (queue_add(&q, (void*)entrance))
		return ((t_point){-1, -1});
	while ((cur = queue_pop(q)))
	{
		while (pt_neighbors(&next, cur, &tile_map->size))
		{
			next_tile = tile_map->tile[PT_AT(next)];
			if (dst_map->value[PT_AT(next)] != 0)
				continue ;
			else if (next_tile == sym[SYM_FULL] || next_tile == sym[SYM_ENTRANCE])
				continue ;
			else if (next_tile == sym[SYM_EXIT])
			{
				queue_free(q, NULL);
				free(q);
				free(cur);
				return (next);
			}
			dst_map->value[PT_AT(next)] = dst_map->value[PTP_AT(cur)] + 1;
			MCK(dup = pt_dup(next), ((t_point){-1, -1}));
			if (queue_add(&q, (void*)dup))
				return ((t_point){-1, -1});
		}
		free(cur);
	}
	return ((t_point){-1, -1});
}
