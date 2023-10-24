/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_command_execute.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

static void manipulate_fd(int i)
{
    if (i == 0)
        dup2(g_data->fd[i][STDOUT_FILENO], STDOUT_FILENO);
	else if (i == g_data->pipe_count)
        dup2(g_data->fd[i - 1][0], 0);
	else
	{
        dup2(g_data->fd[i - 1][0], 0);
        dup2(g_data->fd[i][1], 1);
    }
	if(g_data->input_file > 2)
		dup2(g_data->input_file, 0);
	if(g_data->output_file > 2)
		dup2(g_data->output_file, 1);
}

static void	ft_execute(char *abs_path, char **command, int index, int builtin)
{
	if (abs_path || !builtin)
	{
		if (fork() == CHILD)
		{
			manipulate_fd(index);
			close_pipe_fd();
			if(!builtin)
				nav_builtin(command);
			else
				execve(abs_path, command, g_data->envp);
			exit(1);
		}
		else if (builtin)
			free(abs_path);
	}
	else if (command[0])
	{
		printf("minishelli: %s: command not found\n", command[0]);
		g_data->return_value = 127;
	}
}

void multi_command_execute(t_parse *lst)
{
	char	**command;
	char	*abs_path;
	int		i;
	int		builtin;

	i = 0;
	create_pipe_fd();
	while (lst != NULL)
	{
		if (ft_strcmp(lst->content, "|"))
		{
			command = nav_redirection(lst->content);
			delete_quote(command);
			builtin = builtin_check(command[0]);
			if (builtin)
				abs_path = find_path(command[0]);
			ft_execute(abs_path, command, i, builtin);
			free_command_db(command);
			i++;
		}
		lst = lst->next;
	}
	close_pipe_fd();
	free_fd();
 	while (waitpid(-1, &g_data->return_value, 0) != -1)
				continue ;
}