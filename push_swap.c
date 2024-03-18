/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:33 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/18 18:17:56 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_highnum(t_list *list)
{
	t_list *tmp;
	t_list *max;

	tmp = list;
	max = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->content > max->content)
			max = tmp;
	}
	return (max);
}

t_list	*ft_minnum(t_list *list)
{
	t_list *tmp;
	t_list *min;

	tmp = list;
	min = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->content < min->content)
			min = tmp;
	}
	return (min);
}

void ft_three(t_list *list, char stack)
{
	t_list *max;

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
	t_list *list_b;

	list_b = NULL;
	while (list_a != ft_minnum(list_a))
		ft_reverse_rotate(&list_a, 'a');
	ft_push(&list_a, &list_b, 'b');
	ft_three(list_a, 'a');
	ft_push(&list_b, &list_a, 'a');
}

void	ft_five (t_list *list_a)
{
	t_list *list_b;

	list_b = NULL;
	while (list_a != ft_minnum(list_a))
		ft_reverse_rotate(&list_a, 'a');
	ft_push(&list_a, &list_b, 'b');
	ft_four(list_a);
	ft_push(&list_b, &list_a, 'a');
}

void	ft_fill_list(int *numbers, int size)
{
	t_list *list_a;
	int i;

	list_a = malloc(sizeof(t_list));
	if (list_a == NULL)
		exit(1);
	list_a->content = numbers[0];
	list_a->next = NULL;
	i = 1;
	while (i < size - 1)
		ft_lstadd_back(&list_a, ft_lstnew(numbers[i ++]));
	if (ft_lstsize(list_a) == 3)
		ft_three(list_a, 'a');
	if (ft_lstsize(list_a) == 4)
		ft_four(list_a);
	if (ft_lstsize(list_a) == 5)
		ft_five (list_a);
	ft_lstclear(&list_a, del);
}

int main (int ac, char **av)
{
	if (ac < 2)
		(exit(0));
	ft_check_chr(ac, av);
	return 0;
}