/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:06:10 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:14:53 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data	*g_data;

static void	input_duplication(int	fd_in)
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
	{
		printf("Bad file descriptor error\n");
		return ;
	}
	close(fd_in);
}

static void	output_duplication(int	fd_out)
{
	if (dup2(fd_out, STDOUT_FILENO) < 0)
	{
		printf("Bad file descriptor error\n");
		return ;
	}
	close(fd_out);
}

void	duplication(int	fd_in, int	fd_out)
{
	static int	change = 0;
	static int	std_in;
	static int	std_out;

	if (change == 0)
	{
		std_in = dup(0);
		std_out = dup(1);
		change = 1;
	}
	if (fd_in >= 0)
		input_duplication(fd_in);
	else if (std_in != fd_in)
	{
		if (dup2(std_in, STDIN_FILENO) < 0 && printf("Dup2 error\n"))
			return ;
	}
	if (fd_out >= 0)
		output_duplication(fd_out);
	else if (std_out != fd_out)
	{
		if (dup2(std_out, STDOUT_FILENO) == -1 && printf("Dup2 error\n"))
			return ;
	}
}
