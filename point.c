/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:45:10 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 10:53:53 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "libft.h"
#include <stdlib.h>

int		pt_neighbors(t_point *dst, t_point *pt)
{
	static int		i = 0;
	static t_point	offset[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

	dst->x = offset[i].x + pt->x;
	dst->y = offset[i].y + pt->y;
	i++;
	if (i == 4)
	{
		i = 0;
		return (0);
	}
	return (1);
}

t_point	*pt_dup(t_point p)
{
	t_point	*dup;

	MCK(dup = (t_point*)malloc(sizeof(t_point)), NULL);
	dup->x = p.x;
	dup->y = p.y;
	return (dup);
}
