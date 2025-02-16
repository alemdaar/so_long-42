/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:49:37 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/16 22:53:33 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

void	handle_enemy(t_enemy *enemy, t_map maps, t_indexes *index)
{
	enemy->pos_y[index->n] = index->i;
	enemy->pos_x[index->n] = index->j;
	index->n ++;
}
