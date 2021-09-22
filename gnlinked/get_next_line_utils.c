/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:16:50 by llima-ce          #+#    #+#             */
/*   Updated: 2021/09/21 20:41:01 by llima-ce         ###   ########.fr       */
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
	if (lst[0] == NULL)
		lst[0] = new;
	else
	{
		tmp = lst[0];
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		len;

	tmp = lst;
	len = 0;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
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


void	ft_lstclear(t_list **list)
{
	t_list	*temp;

	temp = list[0];
	while(temp != NULL)
	{
		temp = list[0]->next;
		free(list[0]);
		list[0] = temp;
	}
}
