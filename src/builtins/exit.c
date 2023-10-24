/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

static int	ft_check_str(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			return (1);
		i++;
	}
	return (0);
}

void ft_exit(char **command)
{
	int	exit_value;

	exit_value = 0;
	if (command[2])
	{
		printf("exit\n");
		printf("bash: exit: too many arguments");
		exit (1);
	}
	else if (command[1])
	{
		exit_value = new_atoi(command[1]);
		if (ft_check_str(command[1]) || exit_value == -1)
		{
			printf("bash: exit: %s: numeric argument required\n", command[1]);
			exit(255);
		}
	}
	printf("exit\n");
	exit(exit_value);
}