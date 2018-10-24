/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:32:03 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 10:53:41 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "point.h"
#include "priority_queue.h"
#include "libft.h"

t_point		bfs(t_tile_map *tile_map, t_value_map *dst_map,
	t_point *entrance, t_sym sym)
{
	t_pq	*pq;
	t_point	*cur;
	t_point	*dup;
	t_point	next = {0, 0};
	char	next_tile;

	if (value_map_new(dst_map, &tile_map->size))
		return ((t_point){-1, -1});
	if (pq_add(&pq, (void*)entrance, 0, 0))
		return ((t_point){-1, -1});
	while ((cur = pq_pop(&pq, NULL)))
		while (pt_neighbors(&next, cur))
		{
			next_tile = tile_map->tile[PT_AT(next)];
			if (dst_map->value[PT_AT(next)] != 0)
				continue ;
			else if (next_tile == sym[SYM_FULL])
				continue ;
			else if (next_tile == sym[SYM_EXIT])
				return (next);
			dst_map->value[PT_AT(next)] = dst_map->value[PTP_AT(cur)] + 1;
			MCK(dup = pt_dup(next), ((t_point){-1, -1}));
			if (pq_add(&pq, (void*)dup, 0, 0))
				return ((t_point){-1, -1});
		}
	return ((t_point){-1, -1});
}
