/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:11:57 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 10:56:43 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# define PTP_AT(pt)pt->y][pt->x
# define PT_AT(pt)pt.y][pt.x

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

int				pt_neighbors(t_point *pt, t_point *dst, t_point *bounds);
t_point			*pt_dup(t_point p);

#endif
