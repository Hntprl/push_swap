/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opirations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:11:10 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/26 20:49:21 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list, char stack)
{
	t_list	*tmp;

	if (!(*list) || !(*list)->next || !list)
		return ;
	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = (*list);
	(*list) = tmp;
	if (stack == 'a')
		write(1, "sa\n", 3);
	if (stack == 'b')
		write(1, "sb\n", 3);
}

void	ft_push(t_list **list, t_list **list2, char stack)
{
	t_list	*tmp;

	if (!(*list))
		return ;
	tmp = (*list);
	(*list) = (*list)->next;
	tmp->next = (*list2);
	(*list2) = tmp;
	if (stack == 'a')
		write(1, "pa\n", 3);
	if (stack == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_list **list, char stack)
{
	t_list	*tmp;

	if (!(*list) || !(*list)->next)
		return ;
	tmp = (*list)->next;
	ft_lstadd_back(list, (*list));
	(*list) = tmp;
	if (stack == 'a')
		write(1, "ra\n", 3);
	if (stack == 'b')
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_list **list, char stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*list) || !(*list)->next)
		return ;
	tmp2 = (*list);
	tmp = ft_lstlast((*list));
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	ft_lstadd_front(list, tmp);
	if (stack == 'a')
		write(1, "rra\n", 4);
	if (stack == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rotate_rotate(t_list	**list_a, t_list **list_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*list_a) || !(*list_b) || !(*list_a)->next || !(*list_b)->next)
		return ;
	tmp = (*list_a)->next;
	ft_lstadd_back(list_a, (*list_a));
	(*list_a) = tmp;
	tmp2 = (*list_b)->next;
	ft_lstadd_back(list_b, (*list_b));
	(*list_b) = tmp2;
	write(1, "rr\n", 3);
}
