/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

void	write_export()
{
	int	i;

	i = -1;
	while(g_data->export[++i])
		printf("declare -x %s\n",g_data->export[i]);
}

void    ft_export(char **export_cmd)
{
	int		equals_check;
	int		i;

	i = 1;
	while(export_cmd[i])
	{
		equals_check = equal_sign_index(export_cmd[i]);
        if(equals_check == -1)
		{
			i++;
			continue;
		}
		else if (equals_check != -1)
		{
			if(!export_change_data(export_cmd[i], equals_check))
			{
				update_export(export_cmd[i]);
				sort_export();
				if(equals_check != 0) //eklenicek fonksiyon
					add_env(export_cmd[i]);
			}
		}
		i++;
	}
}


// = değeri var mı?
// eğer varsa bu elaman = den sonra bişi olmasa bile
// env e eklenicek boş olarak
// = öncesinde bir boşluk var mı?
// eşittirin sağında boşluk olamaz.
//

