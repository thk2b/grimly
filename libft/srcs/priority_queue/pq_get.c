/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:14:29 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/22 23:33:56 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "priority_queue.h"

void	*pq_get(t_pq *pq)
{
	return (pq->data);
}
