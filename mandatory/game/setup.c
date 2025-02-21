/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:15:25 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/20 17:09:39 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	set_up(t_game	*game, t_file dafile)
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
	game->win = mlx_new_window(game->mlx, dafile.line_chars * WIN_RULE,
			dafile.count_lines * WIN_RULE, "So_Long");
	if (game->wall_img == NULL || game->player_img == NULL
		|| game->empty_img == NULL || game->coin_img == NULL
		|| game->exit_img == NULL || game->win == NULL)
	{
		free_gmap(game, dafile.count_lines);
		free_mlx(game);
		return (why_exit ("image load or win failed\n", FAILED), FAILED);
	}
	find_player(game);
	calculate_collect(game);
	game->move = 1;
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
