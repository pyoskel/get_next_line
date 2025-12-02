/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:54:08 by pabartoc          #+#    #+#             */
/*   Updated: 2025/12/02 21:18:10 by pabartoc         ###   ########.fr       */
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

char	*gnl_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if ((unsigned char) str[i] == (unsigned char) c)
			return ((char *) &str[i]);
		i++;
	}
	if ((unsigned char) str[i] == (unsigned char) c)
		return ((char *) &str[i]);
	return (NULL);
}

char *gnl_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	total_len;
	size_t	i;
	size_t	n;

	total_len = gnl_strlen(str1) + gnl_strlen(str2);
	result = (char *)malloc((total_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	n = 0;
	while (str1 && str1[i] != '\0')
		result[n++] = str1[i++];
	i = 0;
	while (str2 && str2[i] != '\0')
		result[n++] = str2[i++];
	result[n] = '\0';
	return (result);
}