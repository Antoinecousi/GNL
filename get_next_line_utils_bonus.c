/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:15:40 by acousini          #+#    #+#             */
/*   Updated: 2021/02/02 12:44:55 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2, int reader)
{
	int			i;
	char		*copy;
	int			s1_len;
	int			s2_len;

	s2[reader] = '\0';
	if (!s2 && !s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(copy = malloc(sizeof(char) * ((s1_len + s2_len + 1)))))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		copy[i] = s1[i];
	i--;
	while (i++ < s1_len + s2_len - 1)
		copy[i] = s2[i - s1_len];
	free(s1);
	copy[i] = '\0';
	return (copy);
}

int			get_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
