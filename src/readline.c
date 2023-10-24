/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

t_data *g_data;

void	reading_line(void)
{
	while (1)
	{
		g_data->line = readline("minishelli > ");
		if (g_data->line && *(g_data->line))
		{
			add_history(g_data->line);
			parser();
			syntax_check(g_data->parse);
			if(g_data->syntax_flag == 1 && g_data->heredoc_cnt == 0){
				printf("Syntax error\n");
				re_free();
				continue;
			}
			heredoc_list(g_data->parse);
			if(g_data->syntax_flag == 1){
				printf("Syntax error\n");
				re_free();
				continue;
			}
			if (g_data->syntax_flag == 0)
				nav_execute();
			re_free();
		}
		else 
			free(g_data->line);
		//system("leaks minishelli");
	}
}

// Proje eksikleri
// singal yazılmadı.
// old path ve pwd güncellenmedi.
// Ekstra Düzeltmeler
// -Güzel Harika Karımın kısmında ki " kullanıldığında ki bug düzeltildi.
// -libft split artık tırnak içinde ki boşluklarda ayırmıyor.

// leak yok sıfır. :)
// güncelleme saati sabah 5 amk -_-
// Güncellemeyi yapan -Alp(Bernanın harika mükemmel yakışıklı sevgilisi hehehehehe) <3