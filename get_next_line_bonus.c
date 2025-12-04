/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:46:23 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/04 23:46:20 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	remainder[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (!remainder[fd][0])
		{
			bytes = read(fd, remainder, BUFFER_SIZE);
			if (bytes < 0)
				return (free(line), NULL);
			if (bytes == 0)
				return (line);
			remainder[fd][bytes] = '\0';
		}
		line = gnl_join_chunk(line, remainder[fd]);
		if (!line || gnl_has_newline(remainder[fd]))
			break;
		gnl_clean_buffer(remainder[fd]);
	}
	gnl_clean_buffer(remainder[fd]);
	return (line);
}

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("testfile.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }