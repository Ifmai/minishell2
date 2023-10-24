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

int	is_variable_char(char data)
{
	if (data >= 'A' && data <= 'Z')
		return (1);
	else if (data >= 'a' && data <= 'z')
		return (1);
	else if (data >= '0' && data <= '9')
		return (1);
	else if (data == '_')
		return (1);
	else
		return (0);
}

int	variable_len(char *data)
{
	int	len;

	len = 0;
	if (data[len] == '?')
		return (1);
	while (data[len] != '\0' && is_variable_char(data[len]))
		len++;
	return (len);
}

char	*get_variable(char *input)
{
	char	*var_data;
	char	*temp;
	int		i;

	i = 0;
	if (*input == '$' && *(input + 1) != '\0')
	{
		input++;
		if (*input == '?')
			return (ft_itoa(g_data->return_value % 256));
		i = variable_len(input);
		temp = ft_substr(input, 0, i);
		var_data = ft_strdup(ft_getenv(temp, 0));
		free(temp);
		if (var_data == NULL)
			var_data = ft_strdup("");
		return (var_data);
	}
	else
		return (ft_strdup("$"));
}