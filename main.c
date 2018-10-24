/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:57:25 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/23 22:04:43 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"
#include <fcntl.h>

static void	error(void)
{
	ft_putendl("MAP ERROR");
}

int			main(int ac, char **av)
{
	int	i;
	int	fd;

	i = 1;
	if (ac == 1 && grimly(0))
		error();
	else
		while (av[i])
			if ((fd = open(av[i++], O_RDONLY)) == -1)
				error();
			else if (grimly(fd))
				error();
	return (0);
}
