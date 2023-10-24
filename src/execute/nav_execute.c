/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;


void    nav_execute()
{
    if(g_data->dbl % 2 != 0)
    {
        g_data->dbl++;
        g_data->line = malloc(1 * 1);
    }
    if(g_data->sng % 2 != 0)
    {
        g_data->line = malloc(1 * 1);
        g_data->sng++;
    }
    pipe_counter(g_data->parse);
    if(g_data->pipe_count > 0)
        multi_command_execute(g_data->parse);
    else
        one_command_execute();
}

//pipe count sayıcaz buna göre multi veya one command yönlendirmesi yapıcaz.
//pipe yönlendirmeleri için pipe count kadar bir int double array