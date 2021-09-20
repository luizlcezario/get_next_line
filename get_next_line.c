/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:44 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/20 19:37:43 by llima-ce         ###   ########.fr       */
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
	int		end;
	char	*tmp;

	end = BUFFER_SIZE;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if(bytes_read <= 0)
	{
		return(concat_all(bytes_read, buffer_lists, buffer));
	}
	tmp = ft_strchr(buffer, '\n');
	if (tmp != NULL || bytes_read < BUFFER_SIZE)
	{
		end = tmp - buffer + 1;
		if(!end)
			end = ft_strchr(buffer, '\0') - buffer + 1;
		return(concat_all(end, buffer_lists, buffer));
	}
	tmp = ft_strjoin(*buffer_lists, buffer);
	free_ptr(buffer_lists);
	*buffer_lists = tmp;
	return (read_text(buffer_lists, buffer, fd));
}

static char	*concat_all(int end, char **buffer_lists, char *buffer)
{
	char	*tmp;
	char	*res;

	tmp = NULL;
	res = NULL;
	if(end <= 0)
	{
		if(**buffer_lists == '\0')
			return(NULL);
		res = ft_strdup(*buffer_lists);
		free_ptr(buffer_lists);
		return(res);
	}
	else if(end == BUFFER_SIZE)
		tmp = ft_strdup("");
	else
		tmp = ft_strdup(buffer + end);
	buffer[end] = 0;
	res = ft_strjoin(*buffer_lists, buffer);
	free_ptr(buffer_lists);
	*buffer_lists = tmp;
	return(res);
}
