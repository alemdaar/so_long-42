/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:15:29 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/18 15:10:28 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	check_elements(t_map maps, t_file dafile)
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
			if (maps.map[index.i][index.j] == COLLECT)
				index.c ++;
			else if (maps.map[index.i][index.j] == PLAYER)
				index.p ++;
			else if (maps.map[index.i][index.j] == EXIT)
				index.e ++;
			else if (maps.map[index.i][index.j] == ENEMY)
				index.n ++;
			index.j ++;
		}
		index.i ++;
	}
	check_elements2(index, maps, dafile);
}

void	check_elements2(t_indexes index, t_map maps, t_file dafile)
{
	if (index.c < 1)
		myputstr("no collects\n");
	if (index.e != 1)
		myputstr("exit doesnt equal 1\n");
	if (index.p != 1)
		myputstr("player doesnt equal 1\n");
	if (index.n < 1)
		myputstr("there is no enemy !\n");
	if (index.c < 1 || index.e != 1 || index.p != 1
		|| index.n < 1)
	{
		free_maps(&maps, dafile.count_lines);
		free_maps_c(&maps, dafile.count_lines);
		exit(FAILED);
	}
	return ;
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
	if (daline < 1 || daline > dafile.line_chars || daindex < 1
		|| daindex > dafile.line_chars
		|| maps.tmp_map[daline][daindex] == WALL
		|| maps.tmp_map[daline][daindex] == ENEMY)
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

void	can_reach(t_map maps, t_file dafile)
{
	t_indexes	index;

	index.i = 0;
	while (index.i < dafile.count_lines)
	{
		index.j = 0;
		while (index.j < dafile.line_chars)
		{
			if (maps.tmp_map[index.i][index.j] == COLLECT
				|| maps.tmp_map[index.i][index.j] == EXIT)
			{
				free_maps(&maps, dafile.count_lines);
				free_maps_c(&maps, dafile.count_lines);
				why_exit("E or C cant reach them\n", FAILED);
			}
			index.j ++;
		}
		index.i ++;
	}
}
