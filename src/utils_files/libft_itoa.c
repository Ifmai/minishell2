/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

int	arlen(int n)
{
	long	a;
	int		i;

	i = 0;
	a = n;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void	inarr(char *back, int a, int backlen)
{
	long	n;

	n = a;
	if (n < 0)
	{
		back[0] = '-';
		n *= -1;
	}
	if (n >= 10)
	{
		inarr(back, n / 10, backlen - 1);
		inarr(back, n % 10, backlen);
	}
	if (n < 10)
		back[backlen] = n + 48;
}

char	*ft_itoa(int n)
{
	int		backlen;
	char	*back;

	backlen = arlen(n);
	back = malloc((sizeof(char) * backlen) + 1);
	if (!back)
		return (0);
	inarr(back, n, backlen - 1);
	back[backlen] = '\0';
	return (back);
}