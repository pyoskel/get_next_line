/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:54:08 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/04 21:28:06 by pabartoc         ###   ########.fr       */
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

/**
 * basically ft_strchr but specific to this project
 * Search for a newline.
 * Returns 1 if found, otherwise 0.
 * (Simplified compared to strchr, since we only need bool)
 */
int	gnl_has_newline(const char *buffer)
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

/**
 * basically ft_strjoin but specific to this project
 * Connects ‘line’ with the part of ‘buffer’ up to the first '\n'.
 */
char	*gnl_join_chunk(char *line, char *buffer)
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

/**
 * basically ft_memmove but specific to this project
 * Moves the “rest” (everything after ‘\n’) to the beginning of the buffer.
 * Example: "Hallo\nWelt\0" -> "Welt\0..."
 */
void	gnl_clean_buffer(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i] != '\0')
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}
