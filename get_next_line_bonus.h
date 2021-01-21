/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:16:00 by acousini          #+#    #+#             */
/*   Updated: 2021/01/21 14:18:21 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int					get_next_line(int fd, char **line);
int					get_nl(char *str);
char				*ft_strjoin(char *s1, char *s2, int reader);
size_t				ft_strlen(const char *s);

#endif
