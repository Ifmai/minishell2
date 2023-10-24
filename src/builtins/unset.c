/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

void unset_env(char *var_name) {
    int i = 0;
    char **env;

    env = g_data->envp;

    while (env[i] != NULL) {
        if (!is_env_eq(var_name, env[i])) {
            //verilen env degiskenini buldugumuz icin buraya girdik
            free(env[i]); //o degeri siliyoruz
            //kalan bosluklari doldurmak icin bosluktan sonraki her degeri bir oncekine kaydiriyoruz
            while (env[i] != NULL) {
                env[i] = env[i + 1];
                i++;
            }
            break;
        }
        i++;
    }
}