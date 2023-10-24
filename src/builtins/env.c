/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

void	add_env(char *env_cmd)
{
	char	**new_env;
	int		i;

	i = -1;
	if(!change_data_env(env_cmd))
	{
		new_env = ft_calloc((chardb_len(g_data->envp) + 2), sizeof(char *));
		while (g_data->envp[++i])
			new_env[i] = ft_strdup(g_data->envp[i]);
		new_env[i] = ft_strdup(env_cmd);
		free_command_db(g_data->envp);
		g_data->envp = new_env;
	}
}

void	ft_env()
{
	int	i;

	i = 0;
	while (g_data->envp[i])
		printf("%s\n", g_data->envp[i++]);
}