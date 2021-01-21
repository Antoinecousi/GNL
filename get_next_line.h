/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:16:00 by acousini          #+#    #+#             */
/*   Updated: 2021/01/20 12:50:29 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int					get_next_line(int fd, char **line);
int					get_nl(char *str);
char				*ft_strjoin(char *s1, char *s2);

size_t				ft_strlen(const char *s);

char				*join_str(const char *s1, const char *s2);

#endif
