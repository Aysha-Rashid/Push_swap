/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:05:55 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/06/20 21:39:54 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

char	*get_next_line(int fd);
char	*read_lines(int fd, char *store);
char	*new_line(char *line);
char	*remaining(char *buffer);
char	*ft_gstrchr(const char *s, char c);
char	*ft_gstrdup(char	*s1);
char	*ft_gstrjoin(char *s1, char *s2);
size_t	ft_gstrlen(char *str);
char	*ft_gstr_init(void);
#endif