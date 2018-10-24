/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:04:12 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/22 23:25:32 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"
#include <stdlib.h>

void	pq_free(t_pq *pq, t_pq_del_fn del)
{
	t_pq	*cur;

	cur = pq;
	while (cur)
	{
		del(cur->data);
		free(cur);
	}
}
