/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

int is_env_eq(char *var_name, char *env_content)
{
    int var_len;

    var_len = ft_strlen(var_name);

    //verilen degisken ismi ile o degisken ismi uzunlugu kadar karakteri esit mi ve degiskenden sonra = karakteri var mi diye kontrol ediyoruz
    //eger iki sorgu da dogruysa aradigimiz env degiskeni bu satirdadir
    if (!ft_strncmp(var_name, env_content, var_len) && env_content[var_len] == '=')
        return (0);
    return (1);
}

int is_export_eq(char *var_name, char *env_content)
{
    int var_len;

    var_len = ft_strlen(var_name);

    //verilen degisken ismi ile o degisken ismi uzunlugu kadar karakteri esit mi ve degiskenden sonra = karakteri var mi diye kontrol ediyoruz
    //eger iki sorgu da dogruysa aradigimiz env degiskeni bu satirdadir
    if (!ft_strncmp(var_name, env_content, var_len) && (env_content[var_len] == '=' || env_content[var_len] == 0))
        return (0);
    return (1);
}

int change_data_env(char* var_name)
{
    int     i;
    char    *temp;

    temp = ft_substr(var_name, 0, equal_sign_index(var_name));
    i = 0;
    while (g_data->envp[i])
    {
        if (!is_env_eq(temp, g_data->envp[i]))
        {
			free(temp);
			temp = g_data->envp[i];
			g_data->envp[i] = ft_strdup(var_name);
			free(temp);
			return (1);
		}
        i++;
    }
    free(temp);
    return 0;
}

char *ft_getenv(char* var_name, int flag)
{
    int i;

    i = 0;
    while (g_data->envp[i])
    {
        if (!is_env_eq(var_name, g_data->envp[i]))
        {
            if(flag == 0)
                return (&g_data->envp[i][ft_strlen(var_name) + 1]); //env degiskeninin bulundugu satirdan degisken adi ve = karakterinden sonrasini return ediyoruz
            else
                return (*&g_data->envp[i]);
        }
        i++;
    }    
    return NULL;
}

void    create_envp(char **envp)
{
    int i;

    i = -1;
    g_data->envp = ft_calloc((chardb_len(envp) + 1), sizeof(char *));
    while(envp[++i])
        g_data->envp[i] = ft_strdup(envp[i]);
}