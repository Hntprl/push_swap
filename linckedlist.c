/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linckedlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:10:40 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/18 01:07:47 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int  content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!lst || !new)
		return ;
	p = ft_lstlast(*lst);
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
		p -> next = new;
        new -> next = NULL;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new -> next = *lst;
		*lst = new;
	}
}
void del(void *lst)
{
    free(lst);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(&lst -> content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		p = (*lst)-> next;
		ft_lstdelone(*lst, del);
		(*lst) = p;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst -> next;
		i ++;
	}
	return (i);
}
