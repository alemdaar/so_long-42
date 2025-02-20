/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:58:09 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/20 15:10:44 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	close_window(t_game *game)
{
	free_mlx(game);
	// while (1);
	system("leaks so_long_bonus");
	exit(SUCCEFULL);
}

static int	key_hook(int keycode, t_game *game)
{
	if (keycode == RIGHT || keycode == D_KEY)
		moveplayer(game, 1, 0);
	else if (keycode == LEFT || keycode == A_KEY)
		moveplayer(game, -1, 0);
	else if (keycode == UP || keycode == W_KEY)
		moveplayer(game, 0, -1);
	else if (keycode == DOWN || keycode == S_KEY)
		moveplayer(game, 0, 1);
	else if (keycode == ESC_KEY)
		close_window(game);
	return (0);
}

static void protect_it(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->wall_img = NULL;
	game->empty_img = NULL;
	game->player_img = NULL;
	game->coin_img = NULL;
	game->exit_img = NULL;
	game->enemy_img = NULL;
	game->enemy2_img = NULL;
	game->move = NULL;
	game->count_move = NULL;
	game->enemy = NULL;
}

int	main(int ac, char **av)
{
	t_file		dafile;
	t_map		*maps;
	t_game		game;

	if (ac != 2)
		why_exit("dakhal map mea prog !\n", FAILED);
	maps = (t_map *) malloc (sizeof(t_map));
	if (!maps)
		why_exit("map struct not allocated !\n", FAILED);
	correct_map_file(av[1], &maps, &dafile);
	game.map = maps->map;
	game.count_lines = dafile.count_lines;
	protect_it(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_mlx(&game), why_exit("mlx allocation failed !\n", FAILED), FAILED);
	set_up(&game, dafile);
	draw_map(&game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	
	return (SUCCEFULL);
}
