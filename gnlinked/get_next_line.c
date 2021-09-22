/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:44 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/22 16:50:58 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_all(size_t end, int len, t_list **buffer_lists);
char	*read_text( t_list **buffer_lists, int len, int fd);
char	*leading_old_buffer(size_t end,int len);

char	*g_save_buffer;

char	*get_next_line(int fd)
{
	static t_list	*buffer_lists[MAX_FD + 1];
	char			*resf;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if(g_save_buffer != NULL)
		buffer_lists[fd] = ft_lstnew(g_save_buffer);
	resf = read_text(&buffer_lists[fd], 0, fd);
	if(resf == NULL)
		return(NULL);
	return(resf);
}

char	*read_text( t_list **buffer_lists, int len, int fd)
{
	char	*content;
	ssize_t	bytes_read;
	ssize_t	end;

	end = BUFFER_SIZE;
	content = ft_calloc((BUFFER_SIZE + 1),sizeof(char));
	if(content == NULL)
		return(0);
	bytes_read = read(fd, content, BUFFER_SIZE);
	if(bytes_read <= 0)
	{
		free(content);
		return(concat_all(end, len, &buffer_lists[0]));
	}
	else
		len += bytes_read;
	ft_lstadd_back(&buffer_lists[0], ft_lstnew(content));
	if(ft_strchr(buffer_lists[0]->content, '\n') != NULL)
	{
		end = ft_strchr(content, '\n') - content + 1;
		if(!end)
			end = ft_strchr(content, '\0') - content + 1;
		return(concat_all(end, len, &buffer_lists[0]));
	}
	return (read_text(&buffer_lists[0], len, fd));
}


char	*concat_all(size_t end, int len, t_list **buffer_lists)
{
	int		count;
	int		sizeall;
	t_list	*tmp_list;
	char	*tmp;
	char	*res;

	res = leading_old_buffer(end, len);
	if(res == NULL)
		return(NULL);
	sizeall = 0;
	while(len > 0)
	{
		tmp_list = buffer_lists[0];
		count = 0;
		tmp = (char *)buffer_lists[0]->content;
		if(len != 1)
		{
			while(tmp[count] != 0)
			{
				res[sizeall] = tmp[count];
				sizeall++;
				count++;
			}
			buffer_lists[0] = buffer_lists[0]->next;
			free(tmp_list->content);
			free(tmp_list);
		}
		else
		{
			while(count < (int)end)
			{
				res[sizeall] = tmp[count];
				count++;
				sizeall++;
			}
			if(count + 1 < sizeall && ft_strchr(buffer_lists[0]->content, '\n'))
			{
				g_save_buffer = ft_strchr(buffer_lists[0]->content, '\n') + 1;
			}
			else
			{
				g_save_buffer = NULL;
				buffer_lists[0] = NULL;
				free(tmp_list);
			}
		}	
		len--;
	}
	return(res);
}

char	*leading_old_buffer(size_t end,int len)
{
	int		allSize;
	char	*res;

	if(len == 0 || end == 0)
		return(NULL);
	allSize = ((len - 1 )* BUFFER_SIZE) + end + 1;
	res = (char *)ft_calloc(allSize ,sizeof(char));
	if(res == NULL)
		return(NULL);
	return(res);
}
