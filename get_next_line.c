/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:51:34 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/05 21:43:02 by pabartoc         ###   ########.fr       */
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
				return (line);
			remainder[bytes] = '\0';
		}
		line = gnl_join_chunk(line, remainder);
		if (!line || gnl_has_newline(remainder))
			break ;
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

/**
 * echo -e "\nHello\nmy\nname\nis\nWait?\nWhat\nis\nmy\nname?\n" > testfile.txt
 * cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl && ./gnl
 */

/**
 * for testing very long lines
 * python3 -c "print('A'*5000+'\n'+'H'*3000+'\n'+'X'*7000)" > gnl_long.txt
 * cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl_long && ./gnl_long
 * ./gnl_long | wc -c
 */