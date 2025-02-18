/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:17 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/18 18:15:26 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	correct_map_file(char *input_name, t_map **maps, t_file *dafile)
{
	char		*path;
	t_indexes	index;

	if (map_name(input_name) == FALSE)
		return (why_exit("map name isnt correct\n", FAILED), FAILED);
	path = "maps/";
	index.i = 0;
	index.k = 0;
	dafile->file_name = malloc (sizeof(char) * (15 + mystrlen(input_name) + 1));
	if (!dafile->file_name)
		why_exit("file name didnt allocated !\n", FAILED);
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
	count_lines(dafile);
	(*maps)->map = (char **) malloc (sizeof(char *) * dafile->count_lines);
	if (!(*maps)->map)
		why_exit("map ** not allocated\n", FAILED);
	make_map(*maps, *dafile);
	copy_map(*maps, *dafile);
	check_map(**maps, *dafile);
	check_elements(**maps, *dafile);
	fill_map(**maps, *dafile);
	can_reach(**maps, *dafile);
	free_maps_c(*maps, dafile->count_lines);
	return ;
}

void	count_lines(t_file *dafile)
{
	dafile->count_lines = 0;
	dafile->helper = 0;
	dafile->total_count = 0;
	dafile->fd = open_fd(dafile->file_name);
	while (TRUE)
	{
		if (count_lines_p2(dafile) == FALSE)
			break ;
	}
	if (dafile->count_lines < 3 || dafile->count_lines > 35)
		why_exit("lines are less or too long\n", FAILED);
	if (dafile->total_count < 12)
		why_exit("map is too small\n", FAILED);
	close (dafile->fd);
}

int	count_lines_p2(t_file *dafile)
{
	dafile->current_gnl = get_next_line(dafile->fd);
	if (!dafile->current_gnl && dafile->helper == 0)
		why_exit("get next line failed to read\n", FAILED);
	if (!dafile->current_gnl && dafile->helper)
		return (FALSE);
	dafile->current_gnl = remove_nl(dafile->current_gnl);
	dafile->helper = 1;
	if (dafile->count_lines == FALSE)
		dafile->line_chars = mystrlen(dafile->current_gnl);
	if (dafile->line_chars < 3 || dafile->count_lines > 64)
		why_exit("line is less or too long\n", FAILED);
	else
		check_lines(dafile->current_gnl, dafile->line_chars);
	dafile->total_count += dafile->line_chars;
	dafile->count_lines ++;
	return (TRUE);
}

void	check_lines(char *str, int first_count)
{
	int	second_count;

	second_count = mystrlen(str);
	if (first_count == second_count)
		return ;
	why_exit("lines arent equal\n", FAILED);
}
// fd failed