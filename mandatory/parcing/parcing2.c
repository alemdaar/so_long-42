/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:25 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/20 15:11:31 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	make_map(t_map *maps, t_file *dafile)
{
	t_indexes	index;

	// * map && dafile->file_name
	index.c = FALSE;
	dafile->fd = open_fd(dafile->file_name);
	index.i = 0;
	// * map && dafile->file_name
	if (dafile->fd == -1)
		return (free(dafile->file_name), free(maps), why_exit("fd failed\n", FAILED), FAILED);
	maps->map = (char **) malloc (sizeof(char *) * dafile->count_lines);
	// * map && dafile->file_name
	if (!maps->map)
		return (free(dafile->file_name), free(maps), why_exit("map ** not allocated\n", FAILED), FAILED);
	// * map && dafile->file_name && maps->map
	while (index.i < dafile->count_lines)
	{
		maps->map[index.i] = get_next_line(dafile->fd);
		// * map && dafile->file_name && maps->map && maps->map[index.i]
		if (!maps->map[index.i] && index.c == FALSE)
			return (free(dafile->file_name), free_maps(maps, index.i), free(maps), why_exit("get next line failed to read\n", FAILED), FAILED);
		index.c = TRUE;
		maps->map[index.i] = remove_nl(maps->map[index.i]);
		// * map && dafile->file_name && maps->map && maps->map[index.i]
		if (!maps->map[index.i])
			return (free(dafile->file_name), free_maps(maps, index.i), free(maps), why_exit("remove nl failed !\n", FAILED), FAILED);
		index.i ++;
	}
	return (close (dafile->fd), free (dafile->file_name), SUCCEFULL);
	// * map && maps->map && maps->map[index.i]
}

int	copy_map(t_map *maps, t_file dafile)
{
	// * map && maps->map && maps->map[index.i]
	t_indexes	index;

	maps->tmp_map = (char **) malloc (sizeof(char *) * dafile.count_lines);
	if (!maps->tmp_map)
		return (free_maps(maps, dafile.count_lines), free(maps), why_exit("tmp map not allocated \n", FAILED), FAILED);
	// * map && maps->map && maps->map[index.i] && maps->tmp_map
	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		maps->tmp_map[index.i] = malloc (dafile.line_chars + 1);
		// * map && maps->map && maps->map[index.i] && maps->tmp_map && maps->tmp_map[index.i]
		if (!maps->tmp_map[index.i])
			return (free_maps_c(maps, index.i), free_maps(maps, dafile.count_lines), free(maps), why_exit("tmp map line not allocated \n", FAILED), FAILED);
		index.j = 0;
		while (index.j < dafile.line_chars)
			fill_copy(maps, &index);
		index.i ++;
	}
	return (SUCCEFULL);
}

int	check_map(t_map *maps, t_file dafile)
{
	t_indexes	index;

	index.i = 0;
	// * map && maps->map && maps->map[index.i] && maps->tmp_map && maps->tmp_map[index.i]
	while (index.i < dafile.count_lines)
	{
		if (index.i == 0 || index.i == dafile.count_lines - 1)
		{
			// * map && maps->map && maps->map[index.i] && maps->tmp_map && maps->tmp_map[index.i]
			if (line_is_1(maps->map[index.i]) == FAILED)
				return (free_maps_c(maps, dafile.count_lines), free_maps(maps, dafile.count_lines), free(maps), why_exit("first or last arent correct walls \n", FAILED), FAILED);
		}
		else
			checkcen(maps->map[index.i], dafile.line_chars, maps, dafile);
		index.i ++;
	}
	return (SUCCEFULL);
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

	// * map && maps->map && maps->map[index.i] && maps->tmp_map && maps->tmp_map[index.i]
	index.i = 0;
	while (line[index.i])
	{
		if (index.i == 0 || index.i == count - 1)
		{
			if (line[index.i] != WALL)
				return (free_maps_c(maps, dafile.count_lines), free_maps(maps, dafile.count_lines), free(maps), why_exit("center, 1 or last index != wall\n", FAILED), FAILED);
		}
		else
		{
			if (map_symbols(line[index.i]) == FAILED)
				return (free_maps_c(maps, dafile.count_lines), free_maps(maps, dafile.count_lines), free(maps), why_exit("undefined symbol in the map\n", FAILED), FAILED);
		}
		index.i ++;
	}
	return (SUCCEFULL);
}
