/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opirations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:11:10 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/17 00:01:23 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_list **list)
{
	t_list *tmp;

	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = (*list);
	(*list) = tmp;
}

void ft_push(t_list **list, t_list **list2)
{
   t_list *tmp;
   
	tmp = (*list);
	(*list) = (*list)->next;
	ft_lstadd_front(list2,tmp);
}

void ft_rotate(t_list **list)
{
	t_list *tmp;

	tmp = (*list)->next;
	ft_lstadd_back(list, (*list));
	(*list) = tmp;
}

void ft_reverse_rotate(t_list **list)
{
	t_list *tmp;
	t_list *tmp2;

	tmp2 = (*list);
	tmp = ft_lstlast((*list));
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(list, tmp);
}