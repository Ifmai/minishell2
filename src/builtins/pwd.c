/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

void    ft_pwd()
{
    static int i = 0;
    char *current_directory;
    
    current_directory = malloc(PATH_MAX * 1);
    current_directory = getcwd(current_directory, PATH_MAX);
    if(!current_directory)
        printf(".\n");
    else
        printf("%s\n", current_directory);
    g_data->return_value = 0;
    if(current_directory)
        free(current_directory);
}
