/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tile_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:56:54 by tkobb             #+#    #+#             */
/*   Updated: 2018/10/23 22:11:41 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "parse.h"
#include "get_next_line.h"
#include "libft.h"

static int	validate_row(char *row, int width, t_sym sym)
{
	int	i;

	i = 0;
	while (row[i])
		if (ft_memchr((void*)sym, row[i++], 5) == NULL)
			return (1);
	if (i != width)
		return (1);
	return (0);
}

static int	find_entrance(int y, char *row, t_point *entrance, t_sym sym)
{
	int x;

	x = 0;
	while (row[x])
	{
		if (row[x] == sym[SYM_ENTRANCE])
		{
			if (entrance->x != -1)
				return (1);
			entrance->x = x;
			entrance->y = y;
		}
		x++;
	}
	return (0);
}

static void	*free_rows(char **rows, int y)
{
	int j;

	j = 0;
	while (j < y)
		free(rows[j++]);
	free(rows);
	return (NULL);
}

static char	**read_rows(int fd, t_point *size, t_point *entrance, t_sym sym)
{
	int		y;
	char	**rows;

	MCK(rows = (char**)malloc(sizeof(char*) * size->y), NULL);
	y = 0;
	while (y < size->y)
		if ((get_next_line(fd, rows + y)) != 1)
			return free_rows(rows, y);
		else if (validate_row(rows[y], size->x, sym))
			return free_rows(rows, y + 1);
		else if(find_entrance(y, rows[y], entrance, sym))
			return free_rows(rows, y + 1);
		else
			y++;
	if (y != size->y)
		return free_rows(rows, y);
	if (entrance->x < 0)
		return free_rows(rows, y);
	return (rows);
}

int			read_tile_map(int fd, t_tile_map *tm, t_point *entrance, t_sym sym)
{
	char	*line;

	entrance->x = -1;
	if (get_next_line(fd, &line) != 1)
		return (1);
	if (parse_metadata(line, &tm->size, sym))
	{
		free(line);
		return (1);
	}
	free(line);
	if ((tm->tile = read_rows(fd, &tm->size, entrance, sym)) == NULL)
		return (1);
	if (get_next_line(fd, &line) != 0)
	{
		free(line);
		free_tile_map(tm);
		return (1);
	}
	return (0);
}
