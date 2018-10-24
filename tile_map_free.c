/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tile_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:22:17 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 10:45:20 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include <stdlib.h>

void	tile_map_free(t_tile_map *tm)
{
	int	y;

	y = 0;
	while (y < tm->size.y && tm->tile[y])
		free(tm->tile[y++]);
	free(tm->tile);
}
