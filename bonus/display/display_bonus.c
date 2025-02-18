/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:00:20 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/18 16:31:06 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	myputchar(char c)
{
	write(1, &c, 1);
}

void	myputstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	change_str(t_game *game)
{
	char *str;
	int i;

	*game->count_move += 1;
	str = myitoa(*game->count_move);
	if (!str)
	{
		free_mlx(game);
		why_exit("game move not allocated \n", FAILED);
	}
	i = 0;
	while (str[i])
	{
		game->move[i] = str[i];
		i++;
	}
	free(str);
	str = NULL;
	return ;
}
