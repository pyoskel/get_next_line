/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:52:00 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/04 20:11:31 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for read, write, close
# include <stdlib.h> // for malloc, free
# include <stddef.h> // for size_t
# include <fcntl.h>  // for open and flags (optional)
# include <stdio.h>  // for printf (optional)

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(const char *buffer);
char	*gnl_strjoin(char *line, char *buffer);

#endif