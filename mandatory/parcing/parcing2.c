/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:25 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/15 22:28:58 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	make_map(t_map *maps, t_file dafile)
{
	t_indexes	index;

	index.c = FALSE;
	dafile.fd = open_fd(dafile.file_name);
	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		maps->map[index.i] = (char *) malloc (sizeof(char) * dafile.line_chars + 1);
		if (!maps->map[index.i])
		{
			free_maps(maps, index.i);
			exit(FAILED);
		}
		maps->map[index.i] = get_next_line(dafile.fd);
		if (!maps->map[index.i] && index.c == FALSE)
		{
			free_maps(maps, index.i);
			exit(FAILED);	
		}
		index.c = TRUE;
		maps->map[index.i] = remove_nl(maps->map[index.i]);
		index.i ++;
	}
	return (close (dafile.fd), free (dafile.file_name), SUCCEFULL);
}

void	copy_map(t_map *maps, t_file dafile)
{
	t_indexes index;

	maps->tmp_map = (char **) malloc (sizeof(char *) * dafile.count_lines);
	if (!maps->tmp_map)
	{
		free_maps(maps, dafile.count_lines);
		exit(FAILED);
	}
	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		maps->tmp_map[index.i] = (char *) malloc (sizeof(char) * dafile.line_chars + 1);
		if (!maps->tmp_map[index.i])
		{
			free_maps_c(maps, index.i);
			free_maps(maps, dafile.count_lines);
			exit (FAILED);
		}
		index.j = 0;
		while (index.j < dafile.line_chars)
			fill_copy(maps, &index);
		index.i ++;
	}
}

void check_map(t_map maps, t_file dafile)
{
	t_indexes	index;

	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		if (index.i == 0 || index.i == dafile.count_lines - 1) {
			if (line_is_1(maps.map[index.i]) == FAILED)
			{
				free_maps(&maps, dafile.count_lines);
				free_maps_c(&maps, dafile.count_lines);
				exit (FAILED);	
			}
		}
		else
		 	check_center_walls(maps.map[index.i], dafile.line_chars, maps, dafile);
		index.i ++;
	}
}

int line_is_1 (char *line)
{
	t_indexes	index;

	index.i = 0;
	while (line[index.i])
	{
		if (line[index.i] != '1')
			return (FAILED);
		index.i ++;
	}
	return (SUCCEFULL);
}

void check_center_walls(char *line, int count, t_map maps, t_file dafile)
{
	t_indexes index;

	index.i = 0;
	while (line[index.i])
	{
		if (index.i == 0 || index.i == count - 1)
		{
			if (line[index.i] != '1') {
				free_maps(&maps, dafile.count_lines);
				free_maps_c(&maps, dafile.count_lines);
				exit(FAILED);
			}
		}
		else
		{
			if (map_symbols(line[index.i]) == FAILED)
			{
				free_maps(&maps, dafile.count_lines);
				free_maps_c(&maps, dafile.count_lines);
				exit(FAILED);
			}
		}
		index.i ++;
	}
}
