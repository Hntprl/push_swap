/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:27:50 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/27 01:07:11 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_list **list, char stack)
{
	t_list	*max;

	max = ft_highnum((*list));
	if (max == (*list))
		ft_rotate(list, stack);
	if (max->content == (*list)->next->content)
		ft_reverse_rotate(list, stack);
	if (max->content == (*list)->next->next->content)
	{
		if ((*list)->content > (*list)->next->content)
			ft_swap(list, stack);
	}
}

void	ft_four(t_list **list_a)
{
	t_list	*list_b;

	list_b = NULL;
	while ((*list_a) != ft_minnum((*list_a)))
		ft_reverse_rotate(list_a, 'a');
	ft_push(list_a, &list_b, 'b');
	ft_three(list_a, 'a');
	ft_push(&list_b, list_a, 'a');
}

void	ft_five(t_list **list_a)
{
	t_list	*list_b;

	list_b = NULL;
	while ((*list_a) != ft_minnum((*list_a)))
	{
		if ((*list_a)->next == ft_minnum((*list_a)))
			ft_rotate(list_a, 'a');
		else
			ft_reverse_rotate(list_a, 'a');
	}
	ft_push(list_a, &list_b, 'b');
	ft_four(list_a);
	ft_push(&list_b, list_a, 'a');
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

int	ft_check_space(char *s1, char *s2)
{
	int	s;

	s = 0;
	if (s1[0] == ' ' || s2[0] == ' ' || !s1[0] || !s2[0])
		return (1);
	while (s2[s])
	{
		if (s2[s] == ' ' && s2[s + 1] == ' ')
			return (1);
		if (s2[s] == ' ' && s2[s + 1] == '\0')
			return (1);
		if (!s2[s])
			return (1);
		s++;
	}
	while (s1[s])
	{
		if (s1[s] == ' ' && s1[s + 1] == ' ')
			return (1);
		if (!s1[s])
			return (1);
		s++;
	}
	return (0);
}
