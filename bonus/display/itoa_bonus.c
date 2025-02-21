/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:14:23 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/21 15:08:15 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static	int	len_count(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len += 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	myitoa(t_game *game)
{
	int	count;
	int	n;
	int	tmp;

	n = game->move;
	count = len_count(game->move);
	tmp = 0;
	while (tmp < count)
		game->move_str[tmp++] = 0;
	while (count-- && n)
	{
		game->move_str[count] = (n % 10) + 48;
		n /= 10;
	}
	game->move += 1;
	return ;
}

void	prepare_str(char **str, t_game *game, t_file dafile)
{
	int	i;

	*str = malloc (11);
	if (!*str)
	{
		free_gmap(game, dafile.count_lines);
		free_mlx(game);
		why_exit ("win failed\n", FAILED);
	}
	i = 0;
	while (i < 11)
		str[0][i++] = 0;
	return ;
}
