/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:24:08 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/18 11:38:25 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	put_img(t_game *game, void *img, int x, int y)
{
	int	a;
	int	b;

	a = WIN_RULE * x;
	b = WIN_RULE * y;
	mlx_put_image_to_window(game->mlx, game->win, img, a, b);
}

void put_enemy(t_game *game, int x, int y)
{
	if (*game->enemy == FALSE)
	{
		put_img(game, game->enemy_img, x, y);
		*game->enemy = TRUE;
	}
	if (*game->enemy == TRUE)
	{
		put_img(game, game->enemy_img, x, y);
		*game->enemy = FALSE;
	}
	return ;
}

void	draw_map(t_game *game)
{
	t_indexes	index;

	index.i = 0;
	index.j = 0;
	while (index.i < game->count_lines)
	{
		index.j = 0;
		while (game->map[index.i][index.j])
		{
			if (game->map[index.i][index.j] == WALL)
				put_img(game, game->wall_img, index.j, index.i);
			if (game->map[index.i][index.j] == EMPTY)
				put_img(game, game->empty_img, index.j, index.i);
			if (game->map[index.i][index.j] == PLAYER)
				put_img(game, game->player_img, index.j, index.i);
			if (game->map[index.i][index.j] == COLLECT)
				put_img(game, game->coin_img, index.j, index.i);
			if (game->map[index.i][index.j] == EXIT)
				put_img(game, game->exit_img, index.j, index.i);
			if (game->map[index.i][index.j] == ENEMY)
				put_enemy(game, index.j, index.i);
			index.j++;
		}
		index.i++;
	}
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "move : ");
	mlx_string_put(game->mlx, game->win, 100, 10, 0xFFFFFF, game->move);
}

int	last_move(t_game *game, int x, int y)
{
	if (game->map[game->player_posy + y][game->player_posx + x] == EXIT)
	{
		if (game->collects == 0)
			return (TRUE);
	}
	return (FALSE);
}

void	moveplayer(t_game *game, int x, int y)
{
	if (game->map[game->player_posy + y][game->player_posx + x] == WALL)
		return ;
	if (game->map[game->player_posy + y][game->player_posx + x] == EXIT)
	{
		if (game->collects > 0)
			return ;
	}
	if (last_move(game, x, y) == TRUE)
		close_window(game);
	if (game->map[game->player_posy + y][game->player_posx + x] == COLLECT)
		game->collects --;
	game->map[game->player_posy][game->player_posx] = EMPTY;
	game->player_posx += x;
	game->player_posy += y;
	game->map[game->player_posy][game->player_posx] = PLAYER;
	game->count_move ++;
	change_str(game->move, game->count_lines);
	draw_map(game);
}
