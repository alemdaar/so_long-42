/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:00:20 by oelhasso          #+#    #+#             */
/*   Updated: 2025/02/16 22:28:02 by oelhasso         ###   ########.fr       */
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

void	myputnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			myputstr("-2147483648");
			return ;
		}
		myputchar('-');
		n = -n;
	}
	if (n / 10)
	{
		myputnbr(n / 10);
		myputnbr(n % 10);
	}
	else
		myputchar('0' + n);
}
