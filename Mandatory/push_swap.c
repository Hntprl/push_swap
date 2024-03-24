/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:33 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/24 00:37:12 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_list(int *numbers, int size)
{
	t_list	*list_a;
	int		i;

	list_a = malloc(sizeof(t_list));
	if (list_a == NULL)
		exit(1);
	list_a->content = numbers[0];
	list_a->next = NULL;
	i = 1;
	while (i < size - 1)
		ft_lstadd_back(&list_a, ft_lstnew(numbers[i ++]));
	free(numbers);
	ft_index(list_a);
	ft_sorted_numbers(list_a);
	ft_sorting_func(list_a);
}

void	ft_sorting_func(t_list *list_a)
{
	t_list	*list_b;

	list_b = NULL;
	if (ft_lstsize(list_a) == 3)
		ft_three(&list_a, 'a');
	if (ft_lstsize(list_a) == 4)
		ft_four(&list_a);
	if (ft_lstsize(list_a) == 5)
		ft_five (&list_a);
	if (ft_lstsize(list_a) > 5 && ft_lstsize(list_a) < 200)
		ft_two_hundred(&list_a, list_b, 5);
	if (ft_lstsize(list_a) > 200)
		ft_two_hundred(&list_a, list_b, 9);
	ft_lstclear(&list_a, del);
}

void	ft_two_hundred(t_list **list_a, t_list *list_b, int dev)
{
	t_var	var;

	var.i = 0;
	var.chunk = ft_lstsize((*list_a)) / dev;
	var.m_chunk = var.chunk / 2;
	var.o_chunk = var.chunk;
	while ((*list_a))
	{
		while ((*list_a)->index >= var.chunk)
			ft_rotate(list_a, 'a');
		ft_push(list_a, &list_b, 'b');
		if (list_b->next && list_b->index >= var.m_chunk)
		{
			if ((*list_a) && (*list_a)->index >= var.chunk)
				ft_rotate_rotate(list_a, &list_b);
			else
				ft_rotate(&list_b, 'b');
		}
		if (++var.i >= var.chunk)
		{
			var.m_chunk += var.o_chunk;
			var.chunk += var.o_chunk;
		}
	}
	ft_last_sort(list_b, list_a);
}

void	ft_last_sort(t_list *list_b, t_list **list_a)
{
	t_list	*high;
	int		mid;

	(*list_a) = NULL;
	while (list_b)
	{
		high = ft_highnum(list_b);
		if (list_b == high || list_b->index == high->index - 1)
		{
			ft_push(&list_b, list_a, 'a');
			if ((*list_a)->next && (*list_a)->index > (*list_a)->next->index)
				ft_swap(list_a, 'a');
		}
		mid = ft_lstsize(list_b) / 2;
		if (ft_posmid(list_b) <= mid)
			ft_rotate(&list_b, 'b');
		else
			ft_reverse_rotate(&list_b, 'b');
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		(exit(0));
	ft_check_chr(ac, av);
	return (0);
}
