/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:13:25 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 17:44:37 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data	*g_data;

void	update_export(char *add_export)
{
	char	**new_export;
	int		index;

	index = -1;
	new_export = ft_calloc((chardb_len(g_data->export) + 2), sizeof(char *));
	while (g_data->export[++index])
		new_export[index] = ft_strdup(g_data->export[index]);
	new_export[index] = ft_strdup(add_export);
	free_command_db(g_data->export);
	g_data->export = new_export;
}

int export_change_data(char* var_name, int equals_index)
{
    int		i;
	char	*temp;

    i = 0;
	if(equals_index)
		temp = ft_substr(var_name, 0, equals_index);
	else
		temp = ft_strdup(var_name);
    while (g_data->export[i])
    {
        if (!is_export_eq(temp, g_data->export[i]))
		{
			free(temp);
			temp = g_data->export[i];
			g_data->export[i] = ft_strdup(var_name);
			free(temp);
			if (equals_index)
				add_env(var_name);
			return (1);
		}
        i++;
    }
	free(temp);
    return (0);
}

int	equal_sign_index(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			if(i != 0 && str[i - 1] != 32)
				return i;
			else if (i == 0 || (i != 0 && str[i - 1] == 32))
			{
				printf("minishelli: export: `%s'",str);
				printf(": not a valid identifier.\n");

				return (-1);
			}
		}
		i++;
	}
	return 0;
}

void	create_export()
{
	int	db_len;
	int	i;

	i = 0;
	db_len = chardb_len(g_data->envp);
	g_data->export = ft_calloc(db_len + 1, sizeof(char *));
	while (g_data->envp[i])
	{
		g_data->export[i] = ft_strdup(g_data->envp[i]);
		i++;
	}
}

void	sort_export()
{
	char *tmp;
	int var_len;
	int i;
	int j;

	i = 0;

	var_len = chardb_len(g_data->export);
	i = 0;
	while (i < var_len - 1)
	{
		j = 0;
		while(j < var_len - 1)
		{
			if (strcmp(g_data->export[j], g_data->export[j + 1]) > 0)
			{
				tmp = g_data->export[j];
				g_data->export[j] = g_data->export[j + 1];
				g_data->export[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}