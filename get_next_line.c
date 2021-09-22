/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:44 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/22 19:03:34 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*concat_all(int end, char **buffer_lists, int fl);
static char	*read_text(char **buffer_lists, char *buffer, int fd);

static void	free_ptr(char **ptr)
{
	if(*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char		*buffer_lists[MAX_FD + 1];
	char			*buffer;
	char			*resf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (!buffer_lists[fd])
		buffer_lists[fd] = ft_strdup("");
	resf = read_text(&buffer_lists[fd], buffer, fd);
	free_ptr(&buffer);
	return (resf);
}

static char	*read_text(char **buffer_lists, char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*res;

	res = ft_strchr(*buffer_lists, '\n');
	if (res != NULL)
		return (concat_all(res - *buffer_lists + 1, buffer_lists, 1));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (concat_all(bytes_read, buffer_lists, 0));
	buffer[bytes_read] = 0;
	tmp = ft_strjoin(*buffer_lists, buffer);
	free_ptr(buffer_lists);
	*buffer_lists = tmp;
	return (read_text(buffer_lists, buffer, fd));
}

static char	*concat_all(int end, char **buffer_lists, int fl)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (end <= 0 && fl == 1)
	{
		if (**buffer_lists == '\0')
			return (NULL);
		res = *buffer_lists;
		*buffer_lists = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer_lists, end, BUFFER_SIZE);
	res = *buffer_lists;
	res[end] = 0;
	*buffer_lists = tmp;
	return (res);
}
