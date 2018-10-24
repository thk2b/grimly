/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tile_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:14:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 15:03:41 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"

int	print_tile_map(t_tile_map *tm, int steps)
{
	int y ;

	y = 0;
	while (y < tm->size.y)
		ft_putendl(tm->tile[y++]);
	ft_putstr("RESULT IN ");
	ft_putnbr(steps);
	ft_putendl(" STEPS!");
	return (0);
}
