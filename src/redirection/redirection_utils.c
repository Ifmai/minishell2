/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:23:01 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 17:44:09 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

char	*s2_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		a;

	a = 0;
	i = -1;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1 && s1[++i] != '\0')
		ptr[i] = s1[i];
	while (s2 && s2[a] != '\0')
		ptr[i++] = s2[a++];
	ptr[i] = '\0';
	free(s1);
	free(s2);
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (0);
	if (!s1 || !*s1)
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while ( s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

char	*trim_quote(char *str, int i)
{
	int		n;
	char	c;

	if (str[i] == '"' || str[i] == '\'')
		c = str[i];
	else
		c = 0;
	n = i;
	if (c != 0)
	{
		n++;
		if (str[++i] == c)
			return (NULL);
		while (str[i] != c)
			i++;
	}
	else
	{
		while(str[i] && str[i] != '>' && str[i] != '<' && str[i] != 32)
			i++;
	}
	return (substr(str, n, i - n));
}