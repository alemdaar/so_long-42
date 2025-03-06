/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:22:13 by oelhasso          #+#    #+#             */
/*   Updated: 2025/03/06 12:10:39 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	put_img(t_game game, void *img, int x, int y)
{
	int	a;
	int	b;

	a = WIN_RULE * x;
	b = WIN_RULE * y;
	mlx_put_image_to_window(game.mlx, game.win, img, a, b);
}

static	void	put_enemy(t_game *game, int x, int y)
{
	if (*game->turn_enemy == FALSE)
		put_img(*game, game->enemy_img, x, y);
	if (*game->turn_enemy == TRUE)
		put_img(*game, game->enemy2_img, x, y);
}

void	draw_map(t_game game)
{
	t_indexes	index;

	index.i = 0;
	index.j = 0;
	while (index.i < game.count_lines)
	{
		index.j = 0;
		while (game.map[index.i][index.j])
		{
			if (game.map[index.i][index.j] == WALL)
				put_img(game, game.wall_img, index.j, index.i);
			if (game.map[index.i][index.j] == EMPTY)
				put_img(game, game.empty_img, index.j, index.i);
			if (game.map[index.i][index.j] == PLAYER)
				put_img(game, game.player_img, index.j, index.i);
			if (game.map[index.i][index.j] == COLLECT)
				put_img(game, game.coin_img, index.j, index.i);
			if (game.map[index.i][index.j] == EXIT)
				put_img(game, game.exit_img, index.j, index.i);
			if (game.map[index.i][index.j] == ENEMY)
				put_enemy(&game, index.j, index.i);
			index.j++;
		}
		index.i++;
	}
}

void	draw_win(t_game game)
{
	draw_map(game);
	change_enemy(&game);
	mlx_string_put(game.mlx, game.win, 5, 3, 0xFFFFFF, "move: ");
	mlx_string_put(game.mlx, game.win, 60, 3, 0xFFFFFF, game.move_str);
}

void	moveplayer(t_game *game, int x, int y)
{
	if (game->map[game->posy + y][game->posx + x] == WALL)
		return ;
	if (game->map[game->posy + y][game->posx + x] == EXIT)
	{
		if (game->collects > 0)
			return ;
	}
	if (last_move(game, x, y) == TRUE)
	{
		myputstr("you won\n");
		close_window(game);
	}
	if (game->map[game->posy + y][game->posx + x] == ENEMY)
	{
		myputstr("you lost\n");
		close_window(game);
	}
	if (game->map[game->posy + y][game->posx + x] == COLLECT)
		game->collects --;
	game->map[game->posy][game->posx] = EMPTY;
	game->posx += x;
	game->posy += y;
	game->map[game->posy][game->posx] = PLAYER;
	myitoa(game);
	draw_win(*game);
}
