/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:46:23 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/05 18:10:48 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	remainder[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (!remainder[fd][0])
		{
			bytes = read(fd, remainder[fd], BUFFER_SIZE);
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

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	int		files_open;

// 	// 1. Open files
// 	fd1 = open("testfile1.txt", O_RDONLY);
// 	fd2 = open("testfile2.txt", O_RDONLY);
// 	fd3 = open("testfile3.txt", O_RDONLY);
// 	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
// 	{
// 		printf("Fehler: Konnte eine der Testdateien nicht öffnen.\n");
// 		// To be on the safe side, close any that may be open (quick & dirty for test main).
// 		if (fd1 != -1) close(fd1);
// 		if (fd2 != -1) close(fd2);
// 		if (fd3 != -1) close(fd3);
// 		return (1);
// 	}
// 	printf("--- Start: Alternating reading of 3 files ---\n\n");
// 	files_open = 1;
// 	while (files_open)
// 	{
// 		files_open = 0; // Reset, set to 1 if ANY file still has data
// 		// --- FILE 1 ---
// 		line1 = get_next_line(fd1);
// 		if (line1)
// 		{
// 			printf("[File 1]: %s", line1);
// 			free(line1);
// 			files_open = 1;
// 		}
// 		// --- FILE 2 ---
// 		line2 = get_next_line(fd2);
// 		if (line2)
// 		{
// 			printf("[File 2]: %s", line2);
// 			free(line2);
// 			files_open = 1;
// 		}
// 		// --- FILE 3 ---
// 		line3 = get_next_line(fd3);
// 		if (line3)
// 		{
// 			printf("[File 3]: %s", line3);
// 			free(line3);
// 			files_open = 1;
// 		}
// 	}
// 	printf("\n--- End of reading process ---\n");
// 	// 4. tidying up
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }

/**
 * echo -e "1. Toyota\n1. BMW\n1. Ford\n1. Tesla" > testfile1.txt
 * echo -e "2. Apple\n2. Samsung\n2. Google\n2. Nokia" > testfile2.txt
 * echo -e "3. Microsoft\n3. Amazon\n3. Meta\n3. Alphabet" > testfile3.txt
 * cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line_bonus.c get_next_line_utils.c -o gnl_bonus && ./gnl_bonus
 */