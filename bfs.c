/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:32:03 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/26 21:50:50 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "point.h"
#include "queue.h"
#include "libft.h"

static void		free_all(t_queue *q, t_point *cur)
{
	pt_neighbors(NULL, NULL, NULL);
	queue_free(q, NULL);
	free(q);
	free(cur);
}

static t_point	handle_exit_tile(t_value_map *vm, t_queue *q,
	t_point *cur, t_point exit)
{
	vm->value[PT_AT(exit)] = *cur;
	free_all(q, cur);
	return (exit);
}

static int		handle_empty_tile(t_queue *q,
	t_value_map *dst_map, t_point *next, t_point *parent)
{
	t_point	*dup;

	dst_map->value[PTP_AT(next)] = *parent;
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

	if (value_map_new(dst_map, &tile_map->size) ||
		queue_add(&q, (void*)entrance))
		return ((t_point){-1, -1});
	while ((cur = queue_pop(q)))
	{
		while (pt_neighbors(&next, cur, &tile_map->size))
			if ((next_tile = tile_map->tile[PT_AT(next)]) == sym[SYM_EXIT])
				return (handle_exit_tile(dst_map, q, cur, next));
			else if (dst_map->value[PT_AT(next)].x != -1 ||
				next_tile == sym[SYM_FULL] || next_tile == sym[SYM_ENTRANCE])
				continue ;
			else if (handle_empty_tile(q, dst_map, &next, cur))
			{
				free_all(q, cur);
				return ((t_point){-1, -1});
			}
		free(cur);
	}
	free_all(q, cur);
	return ((t_point){-1, -1});
}
