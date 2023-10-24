/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;


static void	ft_execute(char *abs_path, char **command, int builtin)
{
	if(abs_path || !builtin)
	{
		duplication(g_data->input_file, g_data->output_file);
		if (!builtin)
			nav_builtin(command);
		else if(fork() == CHILD && builtin)
		{
			execve(abs_path, command, g_data->envp);
			exit(1);
		}
		while (waitpid(-1, &g_data->return_value, 0) != -1)
				continue ;
	}
	else if (command[0])
	{
		printf("minishelli: %s: command not found\n", command[0]);
		g_data->return_value = 127;
	}
}

void    one_command_execute()
{
    char    **command;
    char	*abs_path;    
	int		builtin;

    command = nav_redirection(g_data->parse->content);
	delete_quote(command);
	builtin = builtin_check(command[0]);
    if(builtin)
		abs_path = find_path(command[0]);
	ft_execute(abs_path, command, builtin);
	duplication(-2, -2);
	free(abs_path);
	free_command_db(command);
}
