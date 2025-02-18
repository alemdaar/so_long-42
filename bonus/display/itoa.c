/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:09:09 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/17 22:18:15 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static	char *mycalloc(int size)
{
	int		i;
	char	*str;

	str = malloc (size);
	if (!str)
		return(NULL);
	i = 0;
	while (i < 12)
		str[i++] = 0;
	return (str);
}

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
	char	*str;
	int		len;

	len = len_count(n);
	str = mycalloc(12);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[--len] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (len-- && n)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
