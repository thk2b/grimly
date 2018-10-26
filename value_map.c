/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:33:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/26 16:30:43 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"
#include <stdlib.h>

int		value_map_new(t_value_map *vm, t_point *size)
{
	int			y;
	int			x;

	vm->size.x = size->x;
	vm->size.y = size->y;
	y = 0;
	MCK(vm->value = (t_point**)malloc(sizeof(t_point*) * size->y), 1);
	while (y < size->y)
	{
		MCK(vm->value[y] = (t_point*)malloc(sizeof(t_point) * size->x), 1);
		x = 0;
		while (x < size->x)
		{
			vm->value[y][x] = (t_point){-1, -1};
			x++;
		}
		y++;
	}
	return (0);
}

void	value_map_free(t_value_map *vm)
{
	int	y;

	y = 0;
	while (y < vm->size.y)
		free(vm->value[y++]);
	free(vm->value);
}
