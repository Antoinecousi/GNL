/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:13 by acousini          #+#    #+#             */
/*   Updated: 2021/01/20 16:44:15 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_rest(char *rem)
{
	char		*copy;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!rem)
		return (0);
	while (rem[i] != '\n' && rem[i] != '\0')
		i++;
	if (!(copy = malloc(sizeof(char) * ((ft_strlen(rem) - i) + 1))))
		return (0);
	if (rem[i])
		i++;
	while (rem[i])
		copy[j++] = rem[i++];
	copy[j] = '\0';
	free(rem);
	return (copy);
}

/*
char		*get_correct_line(char *str)
{
	int		i;
	char	*remaining;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(remaining = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		remaining[i] = str[i];
		i++;
	}
	remaining[i] = '\0';
	return (remaining);
}
*/

char		*ft_goodline(char *rem)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!rem)
		return (0);
	while (rem[i] != '\n' && rem[i])
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		str[j] = rem[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int			get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*rem[4096];
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!get_nl(rem[fd]) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		rem[fd] = ft_strjoin(rem[fd], buff);
	}
	free(buff);
	*line = ft_goodline(rem[fd]);
	rem[fd] = get_rest(rem[fd]);
	if (reader == 0)
		return (0);
	return (1);
}
