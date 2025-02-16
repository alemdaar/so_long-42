/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:41:05 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/15 22:34:17 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void free_maps(t_map *maps, int last)
{
	t_indexes index;

	index.i= 0;
	if (!maps->map || !maps->map[index.i])
		return ;
	while (index.i < last)
	{
		free(maps->map[index.i]);
		maps->map[index.i] = NULL;
		index.i ++;
	}
	free(maps->map);
	maps->map = NULL;
}
void free_maps_c(t_map *maps, int last)
{
	t_indexes index;

	index.i= 0;
	if (!maps->tmp_map || !maps->tmp_map[index.i])
		return ;
	while (index.i < last)
	{
		free(maps->tmp_map[index.i]);
		maps->tmp_map[index.i] = NULL;
		index.i ++;
	}
	free(maps->tmp_map);
	maps->tmp_map = NULL;
}

void free_mlx(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->count_lines)
	{
		free(game->map[i]);
		game->map[i++] = NULL;
	}
	free(game->map);
	game->map = NULL;
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->coin_img);
	mlx_destroy_image(game->mlx, game->player_img);
	mlx_destroy_image(game->mlx, game->empty_img);
	mlx_destroy_image(game->mlx, game->exit_img);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}
