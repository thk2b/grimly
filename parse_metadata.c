/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:27:19 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/25 12:42:44 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

static int	parse_symbols(char *line, t_sym sym)
{
	size_t	len;
	int		i;

	if ((len = ft_strlen(line)) < 9)
		return (1);
	if (!ft_isdigit(line[len - 6]))
		return (1);
	i = 0;
	while (i < 5)
	{
		sym[i] = line[len - 5 + i];
		i++;
	}
	// line[len - 5] = '\0';
	return (0);
}

static int	parse_size(char *line, t_point *size)
{
	int	squares;

	size->y = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line != 'x')
		return (1);
	size->x = ft_atoi(++line);
	while (ft_isdigit(*line))
		line++;
	if (ft_strlen(line) != 5)
		return (1);
	if (size->x <= 0 || size->y <= 0)
		return (1);
	if ((squares = size->x * size->y) > MAX_MAP
		|| squares < size->x || squares < size->y)
		return (1);
	return (0);
}

int			parse_metadata(char *line, t_point *size, t_sym sym)
{
	if ((parse_symbols(line, sym)))
		return (1);
	if ((parse_size(line, size)))
		return (1);
	return (0);
}
