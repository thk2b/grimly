/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:34:02 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/24 11:48:14 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"

static void	default_del(void *data)
{
	free(data);
}
void		*pq_pop(t_pq **pq, t_pq_del_fn del)
{
	t_pq	*ret;
	void	*data;

	ret = *pq;
	if (ret == NULL)
		return (NULL);
	if (del == NULL)
		del = default_del;
	*pq = ret->next;
	data = ret->data;
	del(ret);
	return (data);
}
