/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:51:34 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/02 21:52:25 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
    {
        if (!remainder[0])
		{
             bytes = read(fd, remainder, BUFFER_SIZE);
             remainder[bytes] = '\0';
        }
        line = gnl_strjoin(line, remainder);
        if (gnl_strchr(remainder))
            break;
        remainder[0] = '\0';
    }
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