/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

void    change_position(char *dir, char *pwd)
{
    char    *old_pwd;
    char    *new_pwd;
    char    buff[PATH_MAX];

    old_pwd = ft_strdup("OLDPWD=");
    old_pwd = ft_strjoin(old_pwd, pwd);
    new_pwd = ft_strdup("PWD=");
    if(chdir(dir) == -1)
    {
        g_data->return_value = 1;
        perror("cd");
    }
    else
    {
        new_pwd =  ft_strjoin(new_pwd, getcwd(buff, PATH_MAX));
        printf("pwd : %s\n",new_pwd);
        printf("old_pwd : %s\n",old_pwd);
        if (!export_change_data(old_pwd, equal_sign_index(old_pwd)))
        {
            printf("buraya ekledim");
            update_export(old_pwd);
            add_env(old_pwd);
        }
        else if (!export_change_data(new_pwd, equal_sign_index(new_pwd)))
        {
            add_env(new_pwd);
            update_export(new_pwd);
        }
        g_data->return_value = 0;
    }
    free(old_pwd);
    free(new_pwd);
}

void     ft_cd(char **command)//command[1]gelcek buraya sadece.
{
    char    *home_dir;
    char    *dir;
    char    *pwd;

    dir = command[1];
    pwd = ft_getenv("PWD", 0);
    if (dir == NULL || !ft_strcmp(dir, "~"))
    {
        home_dir = ft_getenv("HOME", 0);
        if (home_dir == NULL)
        {
            printf("cd: HOME not set");
            g_data->return_value = 1;
        }
        else
            change_position(home_dir, pwd);
    }
    else
        change_position(dir, pwd);
    //free(pwd);
}
//oldpath eklenicek.
//cd ile pwd güncellencek.