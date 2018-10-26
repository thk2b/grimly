/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:42:15 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 19:55:25 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"

static int		is_best_tile(char tile, int value, int min_value, t_sym sym)
{
	if (tile == sym[SYM_ENTRANCE])
		return (1);
	if (value == 0)
		return (0);
	if (min_value == -1 || value < min_value)
		return (1);
	return (0);
}

static t_point	find_min_neighbor(t_tile_map *tile_map, t_value_map *val_map,
	t_point *cur, t_sym sym)
{
	int		min_value;
	t_point	next;
	t_point	best_next;

	min_value = -1;
	while (pt_neighbors(&next, cur, &tile_map->size))
	{
		if (is_best_tile(tile_map->tile[PT_AT(next)],
			val_map->value[PT_AT(next)], min_value, sym))
		{
			min_value = val_map->value[PT_AT(next)];
			best_next = next;
		}
	}
	return (best_next);
}

int				render_path(t_tile_map *tile_map, t_value_map *val_map,
	t_point *exit, t_sym sym)
{
	t_point	cur;
	t_point	next;
	int		steps;

	next.x = 0;
	next.y = 0;
	ft_memcpy(&cur, exit, sizeof(t_point));
	steps = 0;
	while (++steps)
	{
		next = find_min_neighbor(tile_map, val_map, &cur, sym);
		if (tile_map->tile[PT_AT(next)] == sym[SYM_ENTRANCE])
			break ;
		tile_map->tile[PT_AT(next)] = sym[SYM_PATH];
		cur = next;
	}
	return (print_tile_map(tile_map, steps - 1, sym));
}
