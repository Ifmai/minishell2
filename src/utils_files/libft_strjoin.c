/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command_execute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:21:50 by bkiziler          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:08 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"

t_data *g_data;

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		s1;
	size_t	i;

	i = 0;
	s1 = ft_strlen(src);
	if (!dstsize)
		return (s1);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s1);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst && !dstsize)
		return (0);
	i = ft_strlen(dst);
	if (i >= dstsize)
		return (ft_strlen(src) + dstsize);
	ft_strlcpy((dst + i), src, dstsize - i);
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*back;
	size_t	total_len;

	if (!s1 || !s2)
		return (0);
	total_len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	back = malloc(total_len * sizeof(char));
	if (!back)
		return (0);
	ft_strlcpy(back, s1, ft_strlen(s1) + 1);
	ft_strlcat(back, s2, total_len);
	free(s1);
	return (back);
}