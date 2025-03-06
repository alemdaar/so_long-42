/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:23:25 by oelhasso          #+#    #+#             */
/*   Updated: 2025/03/03 02:14:16 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

int	map_name(char *input_name)
{
	t_indexes	index;

	if (mystrlen(input_name) < mystrlen(".ber"))
		return (FALSE);
	index.i = 0;
	while (index.i < mystrlen(input_name))
	{
		if (input_name[index.i] == '.')
		{
			index.c = find_extention(input_name, index.i, ".ber");
			if (index.c == TRUE)
				return (TRUE);
		}
		index.i++;
	}
	return (FALSE);
}

int	find_extention(char *str, int ind, char *word)
{
	t_indexes	index;

	index.j = 0;
	while (str[ind])
	{
		if (str[ind] != word[index.j])
			return (FAILED);
		ind++;
		index.j++;
	}
	if (!str[ind] && !word[index.j])
		return (TRUE);
	return (FALSE);
}
