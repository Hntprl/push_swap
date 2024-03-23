/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:27:50 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/23 20:38:44 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_list *list, char stack)
{
	t_list	*max;

	max = ft_highnum(list);
	if (max == list)
		ft_rotate(&list, stack);
	if (max->content == list->next->content)
		ft_reverse_rotate(&list, stack);
	if (max->content == list->next->next->content)
	{
		if (list->content > list->next->content)
			ft_swap(&list, stack);
	}
}

void	ft_four(t_list *list_a)
{
	t_list	*list_b;

	list_b = NULL;
	while (list_a != ft_minnum(list_a))
		ft_reverse_rotate(&list_a, 'a');
	ft_push(&list_a, &list_b, 'b');
	ft_three(list_a, 'a');
	ft_push(&list_b, &list_a, 'a');
}

void	ft_five(t_list *list_a)
{
	t_list	*list_b;

	list_b = NULL;
	while (list_a != ft_minnum(list_a))
		ft_reverse_rotate(&list_a, 'a');
	ft_push(&list_a, &list_b, 'b');
	ft_four(list_a);
	ft_push(&list_b, &list_a, 'a');
}

void	ft_sorted_numbers(t_list *list_a)
{
	t_list	*tmp;

	tmp = list_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return ;
		tmp = tmp->next;
	}
	ft_lstclear(&list_a, del);
	exit(0);
}
