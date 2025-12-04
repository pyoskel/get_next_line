/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:47:09 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/04 23:44:19 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h> // for read, write, close
# include <stdlib.h> // for malloc, free
# include <stddef.h> // for size_t
// # include <fcntl.h>  // for open and flags (optional)
// # include <stdio.h>  // for printf (optional)

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
int		gnl_has_newline(const char *buffer);
char	*gnl_join_chunk(char *line, char *buffer);
void	gnl_clean_buffer(char *buffer);

#endif