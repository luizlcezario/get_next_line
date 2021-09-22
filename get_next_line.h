/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:46 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/22 16:48:59 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

typedef enum {FALSE = 0, TRUE = !FALSE} t_bool;

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
