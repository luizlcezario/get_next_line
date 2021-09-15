/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:46 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/15 13:31:15 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
char	*g_save_buffer;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nelem, size_t size);
#endif
