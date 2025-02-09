/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:58:09 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/09 17:34:21 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int mystrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void find_extention(char *str, char *word)
{
	t_indexes index;

	index.i = 0;
	while (str[index.i] != '.')
		index.i ++;
	index.j = 0;
	while (str[index.i])
	{
		if (str[index.i] != word[index.j]) {
			printf ("extension not correct\n");
			exit(FALSE);
		}
		index.i++;
		index.j++;
	}
	if (str[index.i] != word[index.j]) {
		printf ("extension not correct, second condition \n");
		exit(FALSE);
	}
	return ;
}

int	map_name(t_file dafile)
{
	t_indexes index;

	if (ft_strlen(dafile.file_name) <= ft_strlen(".ber"))
		return (FALSE);
	index.i = 0;
	while (index.i < ft_strlen(dafile.file_name))
	{
		if (dafile.file_name[index.i] == '.')
			find_extention(dafile.file_name, ".ber");
		index.i++;
	}
	return (TRUE);
}

int	open_fd(char *file_name)
{
	int	fd;

	fd = open((const char *) file_name, O_RDONLY);
	if (fd == -1) {
		printf ("fd failed !");
		exit(FALSE);
	}
	return (fd);
}

void check_lines(char *str, int first_count)
{
	int second_count;

	second_count = mystrlen(str);
	if (first_count == second_count)
		return ;
	printf ("first count doesnt equal the second !\n");
	exit(FALSE);
}

char	*remove_nl(char *current_gnl)
{
	char *new;
	int i;

	i = 0;
	new = (char *) malloc (sizeof (char) * mystrlen(current_gnl));
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

void count_lines(t_file *dafile)
{
	t_indexes index;
	char *str;

	dafile->count_lines = 0;
	dafile->helper = 0;
	dafile->total_count = 0;
	dafile->fd = open_fd(dafile->file_name);
	while (TRUE)
	{
		dafile->current_gnl = get_next_line(dafile->fd);
		if (!dafile->current_gnl && dafile->helper == 0) {
			printf ("get next line failed !\n");
			exit(FALSE);
		}
		if (!dafile->current_gnl && dafile->helper) {
			printf ("no more lines to read !\n");
			break;
		}
		dafile->current_gnl = remove_nl(dafile->current_gnl);
		dafile->helper = 1;
		if (dafile->count_lines == FALSE)
			dafile->line_chars = mystrlen(dafile->current_gnl);
		if (dafile->line_chars < 3) {
			printf ("first line is less that 3\n");
			exit(FALSE);
		}
		else
			check_lines(dafile->current_gnl, dafile->line_chars);
		dafile->total_count += dafile->line_chars;
		dafile->count_lines ++;
	}
	if (dafile->count_lines < 3) {
		printf ("get next line qrat Qal mn 3!\n");
		exit(FALSE);
	}
	if (dafile->total_count < 12) {
		printf ("map count is small !\n");
		exit(FALSE);
	}
	close (dafile->fd);
	return ;
}

int line_is_1 (char *line)
{
	t_indexes index;

	index.i = 0;
	while (line[index.i])
	{
		if (line[index.i] != '1')
			return (FAILED);
		index.i ++;
	}
	return (SUCCEFULL);
}

int map_symbols(char symbol)
{
		return (SUCCEFULL);
	if (symbol == '0')
		return (SUCCEFULL);
	if (symbol == 'P')
		return (SUCCEFULL);
	if (symbol == 'C')
		return (SUCCEFULL);
	if (symbol == 'E')
		return (SUCCEFULL);
	return (FAILED);
}

void check_center_walls(char *line, int count)
{
	t_indexes index;

	index.i = 0;
	while (line[index.i])
	{
		if (index.i == 0 || index.i == line[index.i])
		{
			if (line[index.i] != '1') {
				printf ("center no wall !\n");
				exit(FALSE);
			}
		}
		else
		{
			if (map_symbols(line[index.i]) == FAILED) {
				printf ("invalid map character in the map !\n");
				exit(FALSE);
			}
		}
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
			if (line_is_1(maps.map[index.i]) == FAILED) {
				printf ("walls arent ok\n");
				exit (FAILED);
			}
		}
		else
		 	check_center_walls(maps.map[index.i], dafile.line_chars);
		
		index.i ++;
	}
}

void flood_fill(t_map maps, t_file dafile, int daline, int daindex)
{
	if (daline < 1 || daline > dafile.line_chars || daindex < 1 || daindex > dafile.line_chars || maps.tmp_map[daline][daindex] == '1')
		return ;
	if (maps.tmp_map[daline][daindex] == 'E') {
		maps.tmp_map[daline][daindex] = 'X';
		return ;
	}
	if (maps.tmp_map[daline][daindex] != 'X')
		maps.tmp_map[daline][daindex] = '1';
	flood_fill(maps, dafile, daline + 1, daindex);
	flood_fill(maps, dafile, daline - 1, daindex);
	flood_fill(maps, dafile, daline, daindex + 1);
	flood_fill(maps, dafile, daline, daindex - 1);
	return ;
}

void fill_map(t_map maps, t_file dafile)
{
	t_indexes index;

	index.i = 0;
	while (maps.map[index.i])
	{
		index.j = 0;
		while (maps.map[index.i][index.j])
		{
			if (maps.map[index.i][index.j] == 'P') {
				flood_fill(maps, dafile, index.i, index.j);
				return ;
			}
			index.j ++;
		}		
		index.i ++;
	}
}

void free_maps(t_map maps, int last)
{
	t_indexes index;

	index.i= 0;
	if (!maps.map || !maps.map[index.i])
		return ;
	while (index.i < last)
	{
		free(maps.map[index.i]);
		maps.map[index.i] = NULL;
		index.i ++;
	}
	free(maps.map);
	printf ("maps was freed succefully !\n");
}
void free_str2(char **str, int last)
{
	t_indexes index;

	index.i = 0;
	if (!str || !*str)
		return ;
	while (str[index.i])
	{
		free(str[index.i]);
		str[index.i] = NULL;
		index.i ++;
	}
	free(str);
	printf ("str2 was freed succefully !\n");
}

void	make_map(t_map *maps, t_file dafile)
{
	t_indexes	index;

	dafile.fd = open_fd(dafile.file_name);
	maps->map = (char **) malloc (sizeof(char *) * dafile.count_lines);
	if (!maps->map) {
		printf ("map didnt allocated proparly !\n");
		exit(FAILED);
	}
	index.i = 0;
	index.i = FALSE;
	while (index.i < dafile.count_lines)
	{
		maps->map[index.i] = (char *) malloc (sizeof(char) * dafile.line_chars + 1);
		if (!maps->map[index.i]) {
			printf ("map a str not allocated\n");
			exit (FAILED);
		}
		maps->map[index.i] = get_next_line(dafile.fd);
		printf ("get : %s\n", maps->map[index.i]);
		if (!maps->map[index.i] && index.c == FALSE) {
			free_str2(maps->map, index.i);
			printf ("get next line returns NULL to map\n");
			exit(FALSE);
		}
		index.c = TRUE;
		maps->map[index.i] = remove_nl(maps->map[index.i]);
		index.i ++;
	}
	close (dafile.fd);
	dafile.fd = 0;
	return ;
}

void	copy_map(t_map *maps, t_file dafile)
{
	t_indexes index;

	maps->tmp_map = (char **) malloc (sizeof(char *) * dafile.count_lines);
	if (!maps->tmp_map) {
		printf ("copy map didnt allocated proparly !\n");
		exit(FAILED);
	}
	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		maps->tmp_map[index.i] = (char *) malloc (sizeof(char) * dafile.line_chars + 1);
		if (!maps->tmp_map[index.i]) {
			printf ("copy map a str not allocated\n");
			exit (FAILED);
		}
		index.j = 0;
		while (index.j < dafile.line_chars)
		{
			maps->tmp_map[index.i][index.j] = maps->map[index.i][index.j];
			index.j ++;
		}
		index.i ++;
	}
}

void check_elements2(t_indexes index)
{
	if (index.c < 1) {
		printf ("collectives less than 1");
		exit(FAILED);
	}
	if (index.e != 1) {
		printf ("exit does not euqal 1");
		exit(FAILED);
	}
	if (index.p != 1) {
		printf ("player does not euqal 1");
		exit(FAILED);
	}
	return ;
}

void check_elements(t_map maps, t_file dafile)
{
	t_indexes index;

	index.i = 0;
	index.c = 0;
	index.p = 0;
	index.e = 0;
	while (index.i < dafile.count_lines)
	{
		index.j = 0;
		while (index.j < dafile.line_chars)
		{
			if (maps.map[index.i][index.j] == 'C')
				index.c ++;
			else if (maps.map[index.i][index.j] == 'P')
				index.p ++;
			else if (maps.map[index.i][index.j] == 'E')
				index.e ++;
			index.j ++;
		}
		index.i ++;
	}
	check_elements2(index);
}

void handle_exit(t_map *maps, t_file dafile)
{
	t_indexes index;

	index.i = 0;
	index.e = 0;
	while (index.i < dafile.count_lines)
	{
		index.j = 0;
		while (index.j < dafile.line_chars)
		{
			if (maps->map[index.i][index.j] == 'E') {
				maps->tmp_map[index.i][index.j] = '1';
				index.e ++;
			}
			index.j ++;
		}
		index.i ++;
	}
	if (index.e != 1) {
		printf ("exit does not euqal 1");
		exit(FAILED);
	}
	return ;
}

void can_reach(t_map maps, t_file dafile)
{
	t_indexes index;

	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		index.j = 0;
		while (index.j < dafile.line_chars)
		{
			if (maps.tmp_map[index.i][index.j] == 'C' || maps.tmp_map[index.i][index.j] == 'E') {
				printf ("found C or E after flood fill !\n");
				printf ("in line %d index %d !\n", index.i, index.j);
				printf ("in line %d index %d !\n", index.i, index.j);
				exit(FAILED);
			}
			index.j ++;
		}		
		index.i ++;
	}
}

t_map *correct_map(t_file *dafile)
{
	t_map *maps;

	count_lines(dafile);
	printf ("......\n");
	make_map(maps, *dafile);
	copy_map(maps, *dafile);
	check_map(*maps, *dafile);
	// int i = 0;
	// while (i < dafile->count_lines)
	// 	printf ("map line 1 : %s\n", maps->map[i++]);
	check_elements(*maps, *dafile);
	fill_map(*maps, *dafile);
	can_reach(*maps, *dafile);
	return (maps);
}

void	correct_map_file(t_file *dafile, t_map **maps)
{
	*maps = (t_map *) malloc (sizeof(t_map));
	if (!*maps)
		exit(FAILED);
	if (map_name(*dafile) == FALSE)
		exit(FALSE);
	*maps = correct_map(dafile);
	printf ("parsed perfectly \n");
	return ;
}

void intial_filename(char **file_name, char *av)
{
	int i;

	i = 0;
	*file_name = (char *) malloc (sizeof(char) * mystrlen(av) + 1);
	if (!*file_name)
		exit(FAILED);
	while (av[i])
	{
		file_name[0][i] = av[i];
		i++;
	}
	file_name[0][i] = 0;
}

int main (int ac, char **av)
{
	t_file		dafile;
	t_indexes	index;
	t_map		*maps;

	if (ac != 2)
		return (0);
	intial_filename(&dafile.file_name, av[1]);
	intial_filename(&dafile.file_name_copy, av[1]);
	correct_map_file(&dafile, &maps);
	index.i = 0;
	index.j = 0;
	while (index.i < dafile.count_lines)
	{ 
		index.j = 0;
		while (index.j < dafile.line_chars)
			printf ("%c ", maps->map[index.i][index.j++]);
		printf ("\n");
		index.i++;
	}
	printf ("\n\n");
}
// line :