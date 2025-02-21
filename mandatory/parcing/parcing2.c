/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:25 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/20 15:53:40 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	make_map(t_map *maps, t_file *dafile)
{
	t_indexes	index;

	index.c = FALSE;
	dafile->fd = open_fd(dafile->file_name);
	index.i = 0;
	if (dafile->fd == -1)
		return (free(dafile->file_name), free(maps),
			why_exit("fd failed\n", FAILED), FAILED);
	maps->map = (char **) malloc (sizeof(char *) * dafile->count_lines);
	if (!maps->map)
		return (free(dafile->file_name),
			free(maps), why_exit("map ** not allocated\n", FAILED), FAILED);
	while (index.i < dafile->count_lines)
		make_map2(maps, dafile, &index);
	return (close (dafile->fd), free (dafile->file_name), SUCCEFULL);
}

int	copy_map(t_map *maps, t_file dafile)
{
	t_indexes	index;

	maps->tmp_map = (char **) malloc (sizeof(char *) * dafile.count_lines);
	if (!maps->tmp_map)
		return (free_maps(maps, dafile.count_lines), free(maps),
			why_exit("tmp map not allocated \n", FAILED), FAILED);
	index.i = 0;
	while (index.i < dafile.count_lines)
		copy_map2(maps, dafile, &index);
	return (SUCCEFULL);
}

void	check_map(t_map *maps, t_file dafile)
{
	t_indexes	index;

	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		if (index.i == 0 || index.i == dafile.count_lines - 1)
		{
			if (line_is_1(maps->map[index.i]) == FAILED)
			{
				free_maps_c(maps, dafile.count_lines);
				free_maps(maps, dafile.count_lines);
				free(maps);
				why_exit("first or last arent correct walls \n", FAILED);
			}
		}
		else
			checkcen(maps->map[index.i], dafile.line_chars, maps, dafile);
		index.i ++;
	}
	return ;
}

int	line_is_1(char *line)
{
	t_indexes	index;

	index.i = 0;
	while (line[index.i])
	{
		if (line[index.i] != WALL)
			return (FAILED);
		index.i ++;
	}
	return (SUCCEFULL);
}

int	checkcen(char *line, int count, t_map *maps, t_file dafile)
{
	t_indexes	index;

	index.i = 0;
	while (line[index.i])
	{
		if (index.i == 0 || index.i == count - 1)
		{
			if (line[index.i] != WALL)
			{
				free_maps_c(maps, dafile.count_lines);
				return (free_maps(maps, dafile.count_lines), free(maps),
					why_exit(" != wall\n", FAILED), FAILED);
			}
		}
		else
			checkcen2(line, maps, dafile, &index);
		index.i ++;
	}
	return (SUCCEFULL);
}
