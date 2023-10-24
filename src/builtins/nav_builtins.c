/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;


int builtin_check(char *command)
{
    if (!ft_strcmp(command, "cd") || !ft_strcmp(command, "pwd"))
        return (0);
    else if (!ft_strcmp(command, "echo") || !ft_strcmp(command, "export"))
        return (0);
    else if (!ft_strcmp(command, "unset") || !ft_strcmp(command, "exit"))
        return (0);
    else if (!ft_strcmp(command, "env"))
        return (0);
    else
        return (1);
}

void    nav_builtin(char **command)
{
    if (!ft_strcmp(command[0], "cd"))
        ft_cd(command);
    else if (!ft_strcmp(command[0], "pwd"))
        ft_pwd();
    else if (!ft_strcmp(command[0], "echo"))
        ft_echo(command);
    else if (!ft_strcmp(command[0], "exit"))
        ft_exit(command);
    else if (!ft_strcmp(command[0], "export"))
    {
        if(!command[1])
            write_export();
        else
            ft_export(command);
    }
    else if (!ft_strcmp(command[0], "env"))
        ft_env();
/*     else if (!ft_strcmp(command[0], "unset"))
        ft_unset(); */
}
