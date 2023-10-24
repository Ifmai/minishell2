/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

static char	*char_to_string(char ch)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	str[0] = ch;
	str[1] = '\0';
	return (str);
}

static int	quote_type(char str , int *q_type)
{
	static int hold = 0;

	if(str == '\"' && (hold == 0 || *q_type == DOUBLE_QUOTE))
	{
		*q_type = DOUBLE_QUOTE;
		hold++;
		hold %= 2;
		return (DOUBLE_QUOTE);
	}
	else if (str == '\'' && (hold == 0 || *q_type == SINGLE_QUOTE))
	{
		*q_type = SINGLE_QUOTE;
		hold++;
		hold %= 2;
		return (SINGLE_QUOTE);
	}
	return (0);
}

static char *change_data(char *str)
{
	char	*temp;
	char	*new_data;// geri döncek
	char	*join_data;//eklerken freelencek str de çıkarken freelncek
	int		single_or_double;

	temp = str;
	single_or_double = 0;
	new_data = ft_strdup("");
	while(temp && *temp != 0)
	{
		while(quote_type(*temp, &single_or_double))
			temp++;
		if(temp != 0)
		{
			if(single_or_double != SINGLE_QUOTE && *temp == '$')
			{
				join_data = get_variable(temp++);
				temp += variable_len(temp);
			}
			else
				join_data = char_to_string(*temp++);
			new_data = ft_strjoin(new_data, join_data);
			free(join_data);
		}
	}
	free(str);
	return (new_data);
}

void	delete_quote(char **command)
{
    int		i;

    i = 0;
    while(command[i])
    {
		command[i] = change_data(command[i]);
		i++;
    }
}