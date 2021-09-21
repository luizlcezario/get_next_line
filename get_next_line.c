/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:44 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/20 21:35:10 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*concat_all(int end, char **buffer_lists, char *buffer);
static char	*read_text(char **buffer_lists, char *buffer, int fd);

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_next_line(int fd)
{
	static char		*buffer_lists[MAX_FD + 1];
	char			*buffer;
	char			*resf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(buffer == NULL)
		return(NULL);
	if(!buffer_lists[fd])
		buffer_lists[fd] = ft_strdup("");
	resf = read_text(&buffer_lists[fd], buffer, fd);
	free_ptr(&buffer);
	return(resf);
}
 
static char	*read_text(char **buffer_lists,char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*res;

	res = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if(bytes_read <= 0)
	{
		return(concat_all(bytes_read, buffer_lists, buffer));
	}
	res = ft_strchr(buffer, '\n');
	if (res != NULL || bytes_read < BUFFER_SIZE)
	{
		if(res == NULL)
			res = ft_strchr(buffer, '\0');
		return(concat_all(res - buffer + 1, buffer_lists, buffer));
	}
	tmp = ft_strjoin(*buffer_lists, buffer);
	free_ptr(buffer_lists);
	*buffer_lists = tmp;
	tmp = NULL;
	return (read_text(buffer_lists, buffer, fd));
}

static char	*concat_all(int end, char **buffer_lists, char *buffer)
{
	char	*res;
	char	*tmp;

	res = NULL;
	tmp = NULL;
	if(end <= 0)
	{
		if(**buffer_lists == '\0')
			return(NULL);
		res = ft_strdup(*buffer_lists);
		free_ptr(buffer_lists);
		return(res);
	}
	if(end  != BUFFER_SIZE)
		tmp = ft_strdup(buffer + end);
	buffer[end] = 0;
	res = ft_strjoin(*buffer_lists, buffer);
	free_ptr(buffer_lists);
	*buffer_lists = tmp;
	return(res);
}
