/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:32:03 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 16:33:05 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "point.h"
#include "queue.h"
#include "libft.h"

static t_point	handle_exit_tile(t_queue *q, t_point *cur, t_point exit)
{
	queue_free(q, NULL);
	free(q);
	free(cur);
	pt_neighbors(NULL, NULL, NULL);
	return (exit);
}

static int		handle_empty_tile(t_queue *q,
	t_value_map *dst_map, t_point *next, int value)
{
	t_point	*dup;

	dst_map->value[PTP_AT(next)] = value;
	MCK(dup = pt_dup(next), 1);
	if (queue_add(&q, (void*)dup))
		return (1);
	return (0);
}

t_point			bfs(t_tile_map *tile_map, t_value_map *dst_map,
	t_point *entrance, t_sym sym)
{
	t_queue	*q;
	t_point	*cur;
	t_point	next;
	char	next_tile;

	ft_memset(&next, 0, sizeof(t_point));
	if (value_map_new(dst_map, &tile_map->size) ||
		queue_add(&q, (void*)entrance))
		return ((t_point){-1, -1});
	while ((cur = queue_pop(q)))
	{
		while (pt_neighbors(&next, cur, &tile_map->size))
			if (dst_map->value[PT_AT(next)] != 0 ||
				(next_tile = tile_map->tile[PT_AT(next)]) == sym[SYM_FULL]
				|| next_tile == sym[SYM_ENTRANCE])
				continue ;
			else if (next_tile == sym[SYM_EXIT])
				return (handle_exit_tile(q, cur, next));
			else if (handle_empty_tile(q, dst_map, &next,
				dst_map->value[PTP_AT(cur)] + 1))
				return ((t_point){-1, -1});
		free(cur);
	}
	return ((t_point){-1, -1});
}
