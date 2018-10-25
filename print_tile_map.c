/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tile_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:14:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 11:36:33 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"
#include <unistd.h>

static void	print_metadata(t_point *size, t_sym sym)
{
	ft_putnbr(size->y);
	ft_putstr("x");
	ft_putnbr(size->x);
	write(1, (char*)sym, 5);
	ft_putendl("");
}

int			print_tile_map(t_tile_map *tm, int steps, t_sym sym)
{
	int y;

	y = 0;
	print_metadata(&tm->size, sym);
	while (y < tm->size.y)
		ft_putendl(tm->tile[y++]);
	ft_putstr("RESULT IN ");
	ft_putnbr(steps);
	ft_putendl(" STEPS!");
	return (0);
}
