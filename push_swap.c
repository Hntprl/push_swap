/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarouf <amarouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:15:33 by amarouf           #+#    #+#             */
/*   Updated: 2024/03/21 09:10:30 by amarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(numbers);
	ft_sorted_numbers(list_a);
	if (ft_lstsize(list_a) == 3)
		ft_three(list_a, 'a');
	if (ft_lstsize(list_a) == 4)
		ft_four(list_a);
	if (ft_lstsize(list_a) == 5)
		ft_five (list_a);
	if (ft_lstsize(list_a) > 5 && ft_lstsize(list_a) < 200)
		ft_two_hundred(list_a);
	ft_lstclear(&list_a, del);
}
void	ft_two_hundred(t_list *list_a)
{
	t_list	*list_b;
	t_list	*tmp;
	int		size;
	var 	var;
	
	var.i = 0;
	size = ft_lstsize(list_a);
	var.chunk = ft_lstsize(list_a) / 5;
	var.m_chunk = var.chunk / 2;
	var.o_chunk = var.chunk;
	ft_index(list_a);
	while (list_a)
	{
		while (list_a->index >= var.chunk)
			ft_rotate(&list_a, 'a');
		ft_push(&list_a, &list_b, 'b');
		if (list_b->next && list_b->index >= var.m_chunk)
		{
			if (list_a && list_a->index >= var.chunk)
				ft_rotate_rotate(&list_a, &list_b);
			else
				ft_rotate(&list_b, 'b');
		}
		if (++var.i >= var.chunk)
		{
			var.m_chunk += var.o_chunk;
			var.chunk += var.o_chunk;
		}
	}
	// tmp = list_b;
	// while (size --)
	// 	tmp = tmp->next;
	// tmp->next->next = NULL;
	// while (list_b)
	// {
	// 	printf("%d ", list_b->content);
	// 	list_b = list_b->next;
	// }
}

int	ft_index_count(t_list *val, int min)
{
	int	index;

	index = 0;
	while (val)
	{
		if (val->content < min)
			index++;
		val = val->next;
	}
	return (index);
}

void	ft_index(t_list *list)
{
	t_list	*val;
	t_list	*tmp;
	int		min;
	
	tmp = list;
	while (tmp)
	{
		min = INT_MAX;
		val = list;
		while (val)
		{
			if (val->content >= tmp->content && val->content < min)
				min = val->content;
			val = val->next;
		}
		val = list;
		tmp -> index = ft_index_count(val, min);
		tmp = tmp -> next;
	}
}

int main (int ac, char **av)
{
	if (ac < 2)
		(exit(0));
	ft_check_chr(ac, av);
	return 0;
}