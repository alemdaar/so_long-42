/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:58:09 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/20 15:11:20 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_window(t_game *game)
{
	//game->map && game->map[index.i] && mlx && imgs && win
	free_gmap(game, game->count_lines);
	free_mlx(game);
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
}

// void leak()
// {
// 	system ("leaks so_long");
// }

int	main(int ac, char **av)
{
	t_file		dafile;
	t_map		*maps;
	t_game		game;

	// atexit(leak);
	if (ac != 2)
		why_exit("dakhal map mea prog !\n", FAILED);
	maps = (t_map *) malloc (sizeof(t_map));
	if (!maps)
		why_exit("map struct not allocated !\n", FAILED);
	correct_map_file(av[1], &maps, &dafile);
	// * map && maps->map && maps->map[index.i]
	game.map = maps->map;
	// free_maps(maps, dafile.count_lines);
	free(maps);
	//game->map && game->map[index.i]
	game.count_lines = dafile.count_lines;
	protect_it(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_gmap(&game, dafile.count_lines), why_exit("mlx failed \n", FAILED), FAILED);
	//game->map && game->map[index.i] && mlx
	set_up(&game, dafile);
	//game->map && game->map[index.i] && mlx && imgs && win
	draw_map(game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (SUCCEFULL);
}
