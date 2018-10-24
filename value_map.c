/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:33:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 11:20:10 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"
#include <stdlib.h>

int		value_map_new(t_value_map *vm, t_point *size)
{
	int			y;

	vm->size.x = size->x;
	vm->size.y = size->y;
	y = 0;
	MCK(vm->value = (int**)malloc(sizeof(int*) * size->y), 1);
	while (y < size->y)
		MCK(vm->value[y++] = (int*)ft_memalloc(sizeof(int) * size->x), 1);
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
