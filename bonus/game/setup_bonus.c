/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:22:30 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/21 15:10:42 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static	void	load_img(t_game *game, t_file dafile)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"picss/wall.xpm", &game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"picss/player.xpm", &game->img_width, &game->img_height);
	game->empty_img = mlx_xpm_file_to_image(game->mlx,
			"picss/empty.xpm", &game->img_width, &game->img_height);
	game->coin_img = mlx_xpm_file_to_image(game->mlx,
			"picss/coin.xpm", &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"picss/exit.xpm", &game->img_width, &game->img_height);
	game->enemy_img = mlx_xpm_file_to_image(game->mlx,
			"picss/enemy.xpm", &game->img_width, &game->img_height);
	game->enemy2_img = mlx_xpm_file_to_image(game->mlx,
			"picss/enemy2.xpm", &game->img_width, &game->img_height);
	if (game->wall_img == NULL || game->player_img == NULL
		|| game->empty_img == NULL || game->coin_img == NULL
		|| game->exit_img == NULL || game->enemy_img == NULL
		|| game->enemy2_img == NULL)
	{
		free_gmap(game, dafile.count_lines);
		free_mlx(game);
		why_exit ("image load failed\n", FAILED);
	}
	return ;
}

int	set_up(t_game *game, t_file dafile)
{
	load_img(game, dafile);
	game->win = mlx_new_window(game->mlx, dafile.line_chars * WIN_RULE,
			dafile.count_lines * WIN_RULE, "So_Long");
	if (game->win == NULL)
	{
		free_gmap(game, dafile.count_lines);
		free_mlx(game);
		return (why_exit ("win failed\n", FAILED), FAILED);
	}
	find_player(game);
	calculate_collect(game);
	game->move = 0;
	prepare_str(&game->move_str, game, dafile);
	myitoa(game);
	game->turn_enemy = (int *) malloc (sizeof(int));
	if (!game->turn_enemy)
	{
		free_gmap(game, dafile.count_lines);
		free_mlx(game);
		return (why_exit ("turn enemy failed\n", FAILED), FAILED);
	}
	*game->turn_enemy = 0;
	return (SUCCEFULL);
}

void	find_player(t_game *game)
{
	t_indexes	index;

	index.i = 0;
	while (index.i < game->count_lines)
	{
		index.j = 0;
		while (game->map[index.i][index.j])
		{
			if (game->map[index.i][index.j] == PLAYER)
			{
				game->posx = index.j;
				game->posy = index.i;
				return ;
			}
			index.j ++;
		}
		index.i ++;
	}
}

void	calculate_collect(t_game *game)
{
	t_indexes	index;

	game->collects = 0;
	index.i = 0;
	while (index.i < game->count_lines)
	{
		index.j = 0;
		while (game->map[index.i][index.j])
		{
			if (game->map[index.i][index.j] == COLLECT)
				game->collects ++;
			index.j ++;
		}
		index.i ++;
	}
}
