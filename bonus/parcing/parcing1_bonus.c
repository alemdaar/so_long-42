/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:23:41 by oelhasso          #+#    #+#             */
/*   Updated: 2025/03/03 02:16:48 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

int	correct_map_file(char *input_name, t_map **maps, t_file *dafile)
{
	char		*path;
	t_indexes	index;

	if (map_name(input_name) == FALSE)
	{
		free(*maps);
		why_exit("map name isnt correct\n", FAILED);
	}
	path = "maps/";
	index.i = 0;
	index.k = 0;
	dafile->file_name = malloc (sizeof(char) * (15 + mystrlen(input_name) + 1));
	if (!dafile->file_name)
	{
		free(*maps);
		why_exit("file name didnt allocated !\n", FAILED);
	}
	while (path[index.i])
		dafile->file_name[index.k++] = path[index.i++];
	index.i = 0;
	while (input_name[index.i])
		dafile->file_name[index.k++] = input_name[index.i++];
	dafile->file_name[index.k] = 0;
	correct_map(dafile, maps);
	return (SUCCEFULL);
}

void	correct_map(t_file *dafile, t_map **maps)
{
	count_lines(dafile, maps);
	make_map(*maps, dafile);
	copy_map(*maps, *dafile);
	check_map(*maps, *dafile);
	check_elements(*maps, *dafile);
	fill_map(**maps, *dafile);
	can_reach(*maps, *dafile);
	free_maps_c(*maps, dafile->count_lines);
	return ;
}

int	count_lines(t_file *dafile, t_map **maps)
{
	dafile->count_lines = 0;
	dafile->helper = 0;
	dafile->total_count = 0;
	dafile->fd = open((const char *) dafile->file_name, O_RDONLY);
	if (dafile->fd == -1)
	{
		free(dafile->file_name);
		free(*maps);
		why_exit("fd failed\n", FAILED);
	}
	while (TRUE)
	{
		if (count_lines_p2(dafile, maps) == FALSE)
			break ;
	}
	if (dafile->count_lines < 3 || dafile->count_lines > 35)
		return (free(dafile->file_name), free(*maps),
			why_exit("lines are less or too long\n", FAILED), FAILED);
	if (dafile->total_count < 18)
		return (free(dafile->file_name), free(*maps),
			why_exit("map is too small\n", FAILED), FAILED);
	return (close (dafile->fd), SUCCEFULL);
}

int	count_lines_p2(t_file *dafile, t_map **maps)
{
	dafile->current_gnl = get_next_line(dafile->fd);
	if (!dafile->current_gnl && dafile->helper == 0)
		return (free(dafile->file_name), free(*maps),
			why_exit("get next line failed to read\n", FAILED), FAILED);
	if (!dafile->current_gnl && dafile->helper)
		return (FALSE);
	dafile->current_gnl = remove_nl(dafile->current_gnl);
	dafile->helper = 1;
	if (dafile->count_lines == 0)
		dafile->line_chars = mystrlen(dafile->current_gnl);
	if (dafile->line_chars < 3 || dafile->line_chars > 64)
		return (free(dafile->file_name), free(*maps),
			why_exit("line is less or too long\n", FAILED), FAILED);
	else
		check_lines(dafile->current_gnl, dafile->line_chars,
			maps, dafile->file_name);
	dafile->total_count += dafile->line_chars;
	dafile->count_lines ++;
	free (dafile->current_gnl);
	return (TRUE);
}

int	check_lines(char *str, int first_count, t_map **maps, char *filename)
{
	int	second_count;

	second_count = mystrlen(str);
	if (first_count == second_count)
		return (TRUE);
	return (free(filename), free(*maps),
		why_exit("lines arent equal\n", FAILED), FAILED);
}
