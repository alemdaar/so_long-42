/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:17 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/16 16:17:24 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include <stdio.h>
void	correct_map_file(char *input_name, t_map **maps, t_file *dafile)
{
	char		*path;
	t_indexes	index;

	if (map_name(input_name) == FALSE)
		exit(FAILED);
	path = "mandatory/maps/";
	index.i = 0;
	index.k = 0;
	dafile->file_name = (char *) malloc (sizeof(char) * (mystrlen(path) + mystrlen(input_name) + 1));
	while (path[index.i])
		dafile->file_name[index.k++] = path[index.i++];
	index.i = 0;
	while (input_name[index.i])
		dafile->file_name[index.k++] = input_name[index.i++];
	dafile->file_name[index.k] = 0;
	correct_map(dafile, maps);
	return ;
}

void correct_map(t_file *dafile, t_map **maps)
{
	count_lines(dafile);
	(*maps)->map = (char **) malloc (sizeof(char *) * dafile->count_lines);
	if (!(*maps)->map)
		exit(FAILED);
	make_map(*maps, *dafile);
	copy_map(*maps, *dafile);
	check_map(**maps, *dafile);
	check_elements(**maps, *dafile);
	fill_map(**maps, *dafile);
	can_reach(**maps, *dafile);
	free_maps_c(*maps, dafile->count_lines);
	return ;
}

void count_lines(t_file *dafile)
{
	dafile->count_lines = 0;
	dafile->helper = 0;
	dafile->total_count = 0;
	dafile->fd = open_fd(dafile->file_name);
	while (TRUE)
	{
		if(count_lines_p2(dafile) == FALSE)
			break ;
	}
	if (dafile->count_lines < 3)
		exit(FAILED);
	if (dafile->total_count < 12)
		exit(FAILED);
	
	close (dafile->fd);
}

int count_lines_p2(t_file *dafile)
{
	dafile->current_gnl = get_next_line(dafile->fd);
	if (!dafile->current_gnl && dafile->helper == 0)
		exit(FAILED);
	if (!dafile->current_gnl && dafile->helper)
		return FALSE;
	dafile->current_gnl = remove_nl(dafile->current_gnl);
	dafile->helper = 1;
	if (dafile->count_lines == FALSE)
		dafile->line_chars = mystrlen(dafile->current_gnl);
	printf ("%d\n", dafile->line_chars);
	if (dafile->line_chars < 3 || dafile->count_lines > 64)
		exit(FAILED);
	else
		check_lines(dafile->current_gnl, dafile->line_chars);
	dafile->total_count += dafile->line_chars;
	dafile->count_lines ++;
	return (TRUE);
}

void check_lines(char *str, int first_count)
{
	int second_count;

	second_count = mystrlen(str);
	if (first_count == second_count)
		return ;
	exit(FAILED);
}
