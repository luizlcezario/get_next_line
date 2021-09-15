/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:50 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/15 13:35:30 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


char	*ft_strchr(const char *str, int n)
{
	int	a;

	a = 0;
	while (*(str + a) != (char)n)
	{
		if (*(str + a) == 0)
			return (NULL);
		a++;
	}
	return ((char *)(str + a));
}


t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(1 * sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = (NULL);
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = lst[0];
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_len_s1;
	size_t	str_len_s2;
	char	*res;

	if (!s1 || !s2)
		return (NULL); 
	str_len_s1 = 0;
	str_len_s2 = 0;
	res = malloc(str_len_s2 + str_len_s1 +1 * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[str_len_s1 + str_len_s2] = 0; 
	while(--str_len_s2 != 0)
		res[str_len_s1 + str_len_s2] = s2[str_len_s2];
	while(--str_len_s1 != 0)
		res[str_len_s1] = s1[str_len_s1];
	return (res);
}

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*p;
	size_t	a;

	if(!nelem || !size)
		return(NULL);
	p = malloc(nelem * size);
	if (!p)
		return (NULL);
	a = 0;
	while (a < nelem * size)
	{
		*(unsigned char *)(p + a) = 0;
		a++;
	}
	return (p);
}
