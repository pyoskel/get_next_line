/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:51:34 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/04 21:01:36 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (!remainder[0])
		{
			bytes = read(fd, remainder, BUFFER_SIZE);
			if (bytes < 0)
				return (free(line), NULL);
			if (bytes == 0)
				break;
			remainder[bytes] = '\0';
		}
		line = gnl_strjoin(line, remainder);
		if (gnl_strchr(remainder))
			break;
		gnl_clean_buffer(remainder);
	}
	gnl_clean_buffer(remainder);
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