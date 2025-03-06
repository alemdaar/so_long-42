/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:22:59 by oelhasso          #+#    #+#             */
/*   Updated: 2025/03/06 12:10:52 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	make_map2(t_map *maps, t_file *dafile, t_indexes *index)
{
	maps->map[index->i] = get_next_line(dafile->fd);
	if (!maps->map[index->i] && index->c == FALSE)
	{
		free(dafile->file_name);
		free_maps(maps, index->i);
		free(maps);
		why_exit("get next line failed to read\n", FAILED);
	}
	index->c = TRUE;
	maps->map[index->i] = remove_nl(maps->map[index->i]);
	if (!maps->map[index->i])
	{
		free(dafile->file_name);
		free_maps(maps, index->i);
		free(maps);
		why_exit("remove nl failed !\n", FAILED);
	}
	index->i ++;
	return ;
}

void	copy_map2(t_map *maps, t_file dafile, t_indexes *index)
{
	maps->tmp_map[index->i] = malloc (dafile.line_chars + 1);
	if (!maps->tmp_map[index->i])
	{
		free_maps_c(maps, index->i);
		free_maps(maps, dafile.count_lines);
		free(maps);
		why_exit("tmp map line not allocated \n", FAILED);
	}
	index->j = 0;
	while (index->j < dafile.line_chars)
		fill_copy(maps, index);
	index->i ++;
	return ;
}

void	checkcen2(char *line, t_map *maps, t_file dafile, t_indexes *index)
{
	if (map_symbols(line[index->i]) == FAILED)
	{
		free_maps_c(maps, dafile.count_lines);
		free_maps(maps, dafile.count_lines);
		free(maps);
		why_exit("undefined symbol \n", FAILED);
	}
	return ;
}

int	last_move(t_game *game, int x, int y)
{
	if (game->map[game->posy + y][game->posx + x] == EXIT)
	{
		if (game->collects == 0)
			return (TRUE);
	}
	return (FALSE);
}

void	change_enemy(t_game *game)
{
	if (*game->turn_enemy == FALSE)
		*game->turn_enemy = 1;
	else if (*game->turn_enemy == TRUE)
		*game->turn_enemy = 0;
}
