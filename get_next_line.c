/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:13 by acousini          #+#    #+#             */
/*   Updated: 2021/02/02 12:30:20 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_replace(char *rem)
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
	if (!(copy = malloc(sizeof(char) * ((ft_strlen(rem) - i + 1)))))
		return (0);
	if (rem[i])
		i++;
	while (rem[i])
		copy[j++] = rem[i++];
	copy[j] = '\0';
	free(rem);
	return (copy);
}

char		*ft_goodline(char *rem, char *buffer)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	free(buffer);
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

int			excep(char **line, int fd)
{
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*rem[OPEN_MAX];
	int				reader;

	reader = 1;
	if (excep(line, fd) || !(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!get_nl(rem[fd]) && reader != 0)
	{
		if ((reader = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		rem[fd] = ft_strjoin(rem[fd], buffer, reader);
	}
	*line = ft_goodline(rem[fd], buffer);
	rem[fd] = ft_replace(rem[fd]);
	if (reader == 0)
	{
		free(rem[fd]);
		rem[fd] = 0;
		return (0);
	}
	return (1);
}
