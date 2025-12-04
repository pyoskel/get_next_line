/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:54:08 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/04 20:37:07 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	gnl_strchr(const char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *line, char *buffer)
{
	char	*new_line;
	size_t	len_line;
	size_t	len_buf;
	size_t	total_len;
	size_t	i;

	len_line = gnl_strlen(line);
	len_buf = 0;
	while (buffer[len_buf] != '\0' && buffer[len_buf] != '\n')
		len_buf++;
	if (buffer[len_buf] == '\n')
		len_buf++;
	total_len = len_line + len_buf;
	new_line = (char *)malloc((total_len + 1) * sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	i = -1;
	while (++i < len_line)
		new_line[i] = line[i];
	i = -1;
	while (++i < len_buf)
		new_line[len_line + i] = buffer[i];
	new_line[total_len] = '\0';
	free(line);
	return (new_line);
}
