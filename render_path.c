/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:42:15 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/26 21:39:48 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"

int			render_path(t_tile_map *tile_map, t_value_map *val_map,
	t_point *exit, t_sym sym)
{
	t_point	cur;
	int		steps;

	steps = 0;
	cur = val_map->value[PTP_AT(exit)];
	while (tile_map->tile[PT_AT(cur)] != sym[SYM_ENTRANCE])
	{
		steps++;
		tile_map->tile[PT_AT(cur)] = sym[SYM_PATH];
		cur = val_map->value[PT_AT(cur)];
	}
	return (print_tile_map(tile_map, steps, sym));
}
