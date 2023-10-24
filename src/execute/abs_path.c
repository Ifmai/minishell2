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

static char *try_accses(char *command)
{
	int		i;
	char	*abs_path;
    char    *temp1;
    char    *temp2;
	i = -1;
	while (g_data->path[++i] != 0)
	{
		temp1 = ft_strdup(g_data->path[i]);
		temp2 = ft_strjoin(temp1, "/");
		abs_path = ft_strjoin(temp2, command);
		if (access(abs_path, F_OK) != -1)
        {
            free_command_db(g_data->path);
			return (abs_path);
        }
		free(abs_path);
	}
	return (0);
}

char    *find_path(char *command)
{
    char *abs_path;

    g_data->path = get_path();
    if(command[0] == '/' && access(command, F_OK) != -1)
        return (strdup(command));
    else if (command[0] == '/')
        return (NULL);
    if (!g_data->path)
        return (NULL);
    abs_path = try_accses(command);
    if(abs_path)
        return (abs_path);
    free_command_db(g_data->path);
    return (0);
}