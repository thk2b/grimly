/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:33:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/28 11:23:51 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"
#include <stdlib.h>

int		value_map_new(t_parent_map *pm, t_point *size)
{
	int			y;
	int			x;

	pm->size.x = size->x;
	pm->size.y = size->y;
	y = 0;
	MCK(pm->value = (t_point**)malloc(sizeof(t_point*) * size->y), 1);
	while (y < size->y)
	{
		MCK(pm->value[y] = (t_point*)malloc(sizeof(t_point) * size->x), 1);
		x = 0;
		while (x < size->x)
		{
			pm->value[y][x] = (t_point){-1, -1};
			x++;
		}
		y++;
	}
	return (0);
}

void	value_map_free(t_parent_map *pm)
{
	int	y;

	y = 0;
	while (y < pm->size.y)
		free(pm->value[y++]);
	free(pm->value);
}
