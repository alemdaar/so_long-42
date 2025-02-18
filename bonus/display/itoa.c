/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:09:09 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/18 15:35:00 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

// static	int	alloc(char **str)
// {
// 	int		i;

// 	*str = (char *) malloc (sizeof(char) * 12);
// 	if (!*str)
// 		return (FAILED);
// 	i = 0;
// 	while (i < 12)
// 	{
// 		str[0][i] = '\0';
// 		i++;
// 	}
// 	return (SUCCEFULL);
// }

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

char	*myitoa(int n)
{
	char		*str;
	t_indexes	index;

	index.i = len_count(n);
	index.j = 0;
	str = (char *) malloc (sizeof(char) * 12);
	if (!str)
		return (NULL);
	while (index.j < 12)
		str[index.j++] = 0;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[--index.i] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (index.i-- && n)
	{
		str[index.i] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
