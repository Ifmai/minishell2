/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

void	close_pipe_fd(void)
{
	int	i;

	i = 0;
	while (i < g_data->pipe_count)
	{
		close(g_data->fd[i][0]);
		close(g_data->fd[i][1]);
		i++;
	}
}

void    pipe_counter(t_parse *lst)
{
    t_parse *temp;

    temp = lst;
    while(temp != NULL)
    {
        if(!ft_strcmp(temp->content, "|"))
            g_data->pipe_count++;
        temp = temp->next;
    }
    if (g_data->pipe_count != 0)
        g_data->fd = malloc(g_data->pipe_count * sizeof(int *));
}

void	create_pipe_fd(void)
{
	int	i;

	i = 0;
	while (i < g_data->pipe_count)
	{
		g_data->fd[i] = malloc(sizeof(int) * 2);
		pipe(g_data->fd[i]);
		i++;
	}
}

void	free_fd(void)
{
	int	i;

	i = 0;
	while (i < g_data->pipe_count)
	{
		free(g_data->fd[i]);
		i++;
	}
	free(g_data->fd);
}

char **get_path()
{
    char    *temp;
    char    **path;
    int     i;

    i = 0;
    while(g_data->envp[i])
    {
        if(!ft_strncmp(g_data->envp[i], "PATH=", 5))
        {
            temp = strdup(g_data->envp[i]);
            break;
        }
        i++;
    }
    if(temp)
    {
        i = 0;
        while (temp[i] && temp[i] != '/')
			i++;
        path = libft_split((temp + i), ':');
        free(temp);
        return (path);
    }
    return (0);
}
