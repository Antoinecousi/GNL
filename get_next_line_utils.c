/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:15:40 by acousini          #+#    #+#             */
/*   Updated: 2021/01/20 17:26:33 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char		*join_str(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*remaining;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	stot_len = s1_len + s2_len + 1;
	remaining = malloc(sizeof(char) * stot_len);
	if (!remaining)
		return (0);
	ft_memmove(remaining, s1, s1_len);
	ft_memmove(remaining + s1_len, s2, s2_len);
	remaining[stot_len - 1] = '\0';
	free((char *)s1);
	return (remaining);
}*/

char		*ft_strjoin(char *s1, char *s2)
{
	int			i;
	char		*copy;
	int			s1_len;
	int			s2_len;

	if (!s2 && !s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(copy = malloc(sizeof(char) * ((s1_len + s2_len + 1)))))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		copy[i] = s1[i];
	while (i < s1_len + s2_len)
	{
		copy[i] = s2[i - s1_len];
		i++;
	}
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
