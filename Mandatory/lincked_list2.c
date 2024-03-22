/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lincked_list2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:24:45 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/19 20:58:00 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*ft_lstcopy(t_list	*list)
{
	t_list	*cpy = NULL;
	t_list	*cpy2 = NULL;

	while (list)
	{
		cpy2 = ft_lstnew(list->content);
		ft_lstadd_back(&cpy, cpy2);
		list = list->next;
	}
	return (cpy);
}

// t_list	*ft_deletenode(t_list *list, t_list *dell)
// {
// 	t_list *tmp;
// 	t_list *tmp2;
	
// 	tmp = list;
// 	while (tmp)
// 	{
// 		if (tmp->next == dell)
// 		{
// 			tmp->next = tmp->next->next;
// 			ft_lstdelone(dell, del);
// 		}
// 			tmp = tmp->next;
// 	}
// 	return (list);
// }