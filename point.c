/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:45:10 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 16:09:19 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "libft.h"
#include <stdlib.h>

static int	out_of_bounds(int n, int max)
{
	return (n < 0 || n >= max);
}

int			pt_neighbors(t_point *dst, t_point *pt, t_point *bounds)
{
	static int		i = 0;
	static t_point	offset[4] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
	int				nx;
	int				ny;

	if (i == 4 || dst == NULL)
		return ((i = 0));
	nx = offset[i].x + pt->x;
	ny = offset[i].y + pt->y;
	i++;
	if (out_of_bounds(nx, bounds->x) || out_of_bounds(ny, bounds->y))
		return (pt_neighbors(dst, pt, bounds));
	dst->x = nx;
	dst->y = ny;
	return (1);
}

t_point		*pt_dup(t_point p)
{
	t_point	*dup;

	MCK(dup = (t_point*)malloc(sizeof(t_point)), NULL);
	dup->x = p.x;
	dup->y = p.y;
	return (dup);
}
