/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:24:08 by oelhasso          #+#    #+#             */
/*   Updated: 2025/03/03 02:27:54 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

int	check_elements(t_map *maps, t_file dafile)
{
	t_indexes	index;

	index.i = 0;
	index.c = 0;
	index.p = 0;
	index.e = 0;
	index.n = 0;
	while (index.i < dafile.count_lines)
	{
		index.j = 0;
		while (index.j < dafile.line_chars)
		{
			if (maps->map[index.i][index.j] == COLLECT)
				index.c ++;
			else if (maps->map[index.i][index.j] == PLAYER)
				index.p ++;
			else if (maps->map[index.i][index.j] == EXIT)
				index.e ++;
			else if (maps->map[index.i][index.j] == ENEMY)
				index.n++;
			index.j ++;
		}
		index.i ++;
	}
	return (check_elements2(index, maps, dafile), SUCCEFULL);
}

int	check_elements2(t_indexes index, t_map *maps, t_file dafile)
{
	int	r;

	r = FALSE;
	if (index.c < 1)
		myputstr("no collects\n");
	if (index.e != 1)
		myputstr("exit doesnt equal 1\n");
	if (index.p != 1)
		myputstr("player doesnt equal 1\n");
	if (index.n < 1)
		myputstr("no enemy \n");
	if (index.c < 1 || index.e != 1
		|| index.p != 1 || index.n < 1)
	{
		free_maps_c(maps, dafile.count_lines);
		return (free_maps(maps, dafile.count_lines),
			free(maps), exit(FAILED), FAILED);
	}
	return (SUCCEFULL);
}

void	fill_map(t_map maps, t_file dafile)
{
	t_indexes	index;

	index.i = 0;
	while (maps.map[index.i])
	{
		index.j = 0;
		while (maps.map[index.i][index.j])
		{
			if (maps.map[index.i][index.j] == PLAYER)
			{
				flood_fill(maps, dafile, index.i, index.j);
				return ;
			}
			index.j ++;
		}
		index.i ++;
	}
}

void	flood_fill(t_map maps, t_file dafile, int daline, int daindex)
{
	if (daline < 1 || daline > dafile.count_lines)
		return ;
	if (daindex < 1 || daindex > dafile.line_chars)
		return ;
	if (maps.tmp_map[daline][daindex] == WALL)
		return ;
	if (maps.tmp_map[daline][daindex] == ENEMY)
		return ;
	if (maps.tmp_map[daline][daindex] == 'X')
		return ;
	if (maps.tmp_map[daline][daindex] == EXIT)
	{
		maps.tmp_map[daline][daindex] = 'X';
		return ;
	}
	if (maps.tmp_map[daline][daindex] != 'X')
		maps.tmp_map[daline][daindex] = WALL;
	flood_fill(maps, dafile, daline + 1, daindex);
	flood_fill(maps, dafile, daline - 1, daindex);
	flood_fill(maps, dafile, daline, daindex + 1);
	flood_fill(maps, dafile, daline, daindex - 1);
	return ;
}

int	can_reach(t_map *maps, t_file dafile)
{
	t_indexes	index;

	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		index.j = 0;
		while (index.j < dafile.line_chars)
		{
			if (maps->tmp_map[index.i][index.j] == COLLECT
				|| maps->tmp_map[index.i][index.j] == EXIT)
			{
				free_maps_c(maps, dafile.count_lines);
				free_maps(maps, dafile.count_lines);
				free(maps);
				return (why_exit("E or C cant reach them\n", FAILED), FAILED);
			}
			index.j ++;
		}
		index.i ++;
	}
	return (SUCCEFULL);
}
