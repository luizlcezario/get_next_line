/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:44 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/15 13:30:45 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_all(size_t end,int len,t_list **first_list);
size_t	read_text(int fd, t_list **first_list);

char	*leading_old_buffer(size_t end,int len);

char	*get_next_line(int fd)
{
	t_list	*tmp;
	t_list	**first_list;
	char	*resf;
	int		len_list;
	size_t	i;

	first_list = (t_list **)ft_calloc(2 ,sizeof(t_list *));
	if(!first_list)
		return (NULL);
	if(g_save_buffer)
		first_list[0] = ft_lstnew(g_save_buffer);
	i = read_text(fd, first_list);
	if(!i)
		return(NULL);
	tmp = first_list[0];
	len_list = 0;
	while(tmp != NULL)
	{
		tmp = tmp->next;
		len_list++;
	}
	resf = concat_all(i, len_list, first_list);
	return(resf);
}

size_t	read_text(int fd, t_list **first_list)
{
	char	*content;
	t_list	*new_read;
	size_t	end;

	
	content = ft_calloc(BUFFER_SIZE + 1,sizeof(char *));
	if(content == NULL)
		return(0);
	if(first_list[0] != NULL)
	{
		if(ft_strchr(first_list[0]->content, '\n') != NULL)
		{
			end = ft_strchr(first_list[0]->content, '\n') - (char *)
					first_list[0]->content + 1;
			return(end);
		}
	}
	read(fd, content, BUFFER_SIZE);
	new_read = ft_lstnew(content);
	ft_lstadd_back(first_list, new_read);
	if(ft_strchr(new_read->content, '\n') != NULL)
	{
		end = ft_strchr(new_read->content, '\n') - content + 1;
		return(end);
	}
	return (read_text(fd, first_list));
}


char	*concat_all(size_t end,int len, t_list **first_list)
{

	int	count;
	int sizeall;
	t_list	*tmp_list;
	char	*tmp;
	char	*res;

	res = leading_old_buffer(end, len);
	if(res == NULL)
		return(NULL);
	sizeall = 0;
	while(len > 0)
	{
		count = 0;
		tmp_list = first_list[0];
		tmp = (char *)tmp_list->content;
		if(len != 1)
		{
			while(tmp[count] != 0)
			{
				res[sizeall] = tmp[count];
				sizeall++;
				count++;
			}
			first_list[0] = first_list[0]->next;
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
			if(count + 1 < sizeall)
				g_save_buffer = ft_strchr(first_list[0]->content, '\n') + 1;
			else
				g_save_buffer = NULL;
		}
		len--;
	}
	return(res);
}

char	*leading_old_buffer(size_t end,int len)
{
	size_t	allSize;
	char	*res;

	allSize = ((len - 1 )* BUFFER_SIZE) + end + 1;
	res = (char *)ft_calloc(allSize, sizeof(char));
	if(res == NULL)
		return(NULL);
	return(res);
}
