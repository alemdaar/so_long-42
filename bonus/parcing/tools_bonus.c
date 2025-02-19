/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:29:41 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/18 12:27:55 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

int	mystrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	open_fd(char *file_name)
{
	int	fd;

	fd = open((const char *) file_name, O_RDONLY);
	if (fd == -1)
		why_exit("fd failed\n", FAILED);
	return (fd);
}

char	*remove_nl(char *current_gnl)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *) malloc (sizeof (char) * mystrlen(current_gnl) + 1);
	while (current_gnl[i])
	{
		new[i] = current_gnl[i];
		i++;
	}
	if (new[i - 1] == '\n')
		new[i - 1] = 0;
	new[i] = 0;
	free(current_gnl);
	return (new);
}

int	map_symbols(char symbol)
{
	if (symbol == WALL)
		return (SUCCEFULL);
	if (symbol == EMPTY)
		return (SUCCEFULL);
	if (symbol == PLAYER)
		return (SUCCEFULL);
	if (symbol == COLLECT)
		return (SUCCEFULL);
	if (symbol == EXIT)
		return (SUCCEFULL);
	if (symbol == ENEMY)
		return (SUCCEFULL);
	return (FAILED);
}

void	fill_copy(t_map *maps, t_indexes *index)
{
	maps->tmp_map[index->i][index->j] = maps->map[index->i][index->j];
	index->j ++;
}
