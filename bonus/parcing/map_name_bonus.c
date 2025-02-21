/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:23:25 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/20 16:23:36 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

int	map_name(char *input_name)
{
	t_indexes	index;

	if (mystrlen(input_name) <= mystrlen(".ber"))
		return (FALSE);
	index.i = 0;
	while (index.i < mystrlen(input_name))
	{
		if (input_name[index.i] == '.')
			find_extention(input_name, ".ber");
		index.i++;
	}
	return (TRUE);
}

void	find_extention(char *str, char *word)
{
	t_indexes	index;

	index.i = 0;
	while (str[index.i] != '.')
		index.i ++;
	index.j = 0;
	while (str[index.i])
	{
		if (str[index.i] != word[index.j])
			why_exit("map name isnt correct\n", FAILED);
		index.i++;
		index.j++;
	}
	if (str[index.i] != word[index.j])
		why_exit("map name isnt correct\n", FAILED);
	return ;
}
